#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<iomanip>
using namespace std;

class node {
private:
int regNum;
node* next;
public:
node* head;
node();
void insert(int);
void print();
void remove(int);
};


class tree {
private:
tree* left;
tree* right;
int coursecode;
node students;

public:
tree* insert(int, tree*);
void studentInsert(int, int, tree*);
void studentDisplay(int, tree*);
void studentRemove(int, int, tree*);
tree* search(int, tree*);
void display(tree*);
tree* min(tree*);
void max(tree*);
int height(tree*);
tree* remove(tree*, int);
tree* right_rot(tree*);
tree* left_rot(tree*);
tree* lr_rot(tree*);
tree* rl_rot(tree*);
void prettyPrint(tree*, int);
};

void tree::studentRemove(int coursecode, int regNum, tree* root){
  root = search(coursecode, root);
  root -> students.remove(regNum);
}

void node::remove(int regNum){

  node *curr = this->head, *prev = NULL;
  while(curr && curr->regNum != regNum)
  {
      prev = curr;
      curr = curr->next;
  }
  if(!curr)
  {
      cout << "Cannot Delete.\n";
      return;
  }
  if(curr == this->head)
  {
      this->head = this->head->next;
  }
  else
      prev->next = curr->next;
  delete curr;
}

void tree::studentInsert(int coursecode, int reg, tree* root){

        root = search(coursecode, root);
        if (root) {
          root -> students.insert(reg);
        }


}

void tree::studentDisplay(int coursecode, tree* root){

        root = search(coursecode, root);
        if (root) {
          root -> students.print();
        }


}

node:: node(){
        this->head = NULL;
}

void node::insert( int regNum ){
        node* temp = new node();
        temp->regNum = regNum;
        temp->next = NULL;
        if (this->head == NULL) {
                /* code */
                head = temp;
        } else{
                node* temp1 = this->head;
                while(temp1->next) {
                        temp1 = temp1->next;
                }
                temp1->next = temp;
        }
}

void node::print(){

        node* temp = this->head;
        if(!temp) cout<< "No students enrolled in this course! "<<endl;
        while(temp) {
                cout<< temp->regNum <<"\n";
                temp = temp->next;
        }
}

void tree::prettyPrint(tree* p, int indent)
{
        if(p != NULL) {
                if(p->right) {
                        prettyPrint(p->right, indent+4);
                }
                if (indent) {
                        std::cout << std::setw(indent) << ' ';
                }
                if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
                std::cout<< p->coursecode << "\n ";
                if(p->left) {
                        std::cout << std::setw(indent) << ' ' <<" \\\n";
                        prettyPrint(p->left, indent+4);
                }
        }
}

tree* tree::right_rot(tree* t){
        tree* u = t->left;
        t->left = u->right;
        u->right = t;
        return u;

}

tree* tree::left_rot(tree* t){
        tree* u = t->right;
        t->right = u->left;
        u->left = t;
        return u;
}

tree* tree::rl_rot(tree* t){
        t->right = right_rot(t->right);
        return left_rot(t);
}

tree* tree::lr_rot(tree* t){
        t->left = left_rot( t->left);
        return right_rot(t);
}

tree* tree::remove(tree* root, int coursecode){
        // base case
        if (root == NULL) {
                cout << "COURSE NOT FOUND." <<endl;
                return root;
        } else if (coursecode > root->coursecode) {
                root->right = remove(root->right, coursecode);
        } else if(coursecode < root->coursecode) {
                root->left = remove(root->left, coursecode);
        } else{
                // three cases
                // Case 1: No child
                if(root->left == NULL && root->right == NULL) {
                        delete root;
                        root = NULL;
                }

                // Case 2: One child
                else if(root->left == NULL) {
                        tree* temp = root;
                        root = root->right;
                        delete temp;

                } else if(root->right == NULL) {
                        tree* temp = root;
                        root = root->left;
                        delete temp;
                } else { // Case 3: Two children
                        tree* temp = min(root->right);
                        root->coursecode = temp->coursecode;
                        root->right = remove(root->right, temp->coursecode);
                }

        }

        if(height(root->left) - height(root->right) == 2)
        {
                // right right case
                if(height(root->left->left) - height(root->left->right) == 1)
                        return left_rot(root);
                // right left case
                else
                        return rl_rot(root);
        }
        // If right node is deleted, left case
        else if(height(root->right) - height(root->left) == 2)
        {
                // left left case
                if(height(root->right->right) - height(root->right->left) == 1)
                        return right_rot(root);
                // left right case
                else
                        return lr_rot(root);
        }

        return root;


}

tree* tree::insert(int coursecode, tree* root){
        if ( root == NULL) {
                tree* temp = new tree();
                temp->coursecode = coursecode;
                temp->left = NULL;
                temp->right = NULL;
                return temp;
        } else if( coursecode < root->coursecode) {
                root->left = insert(coursecode, root->left);
                if (height(root->left) - height(root->right) == 2) {
                        if ( coursecode < root->left->coursecode) {
                                root = right_rot(root);
                        } else root =  lr_rot(root);
                }
        } else{
                root->right = insert(coursecode, root->right);
                if (height(root->right) - height(root->left) == 2) {
                        if (coursecode > root->right->coursecode ) {
                                root = left_rot(root);
                        } else root = rl_rot(root);
                }
        }
        return root;
}

tree* tree::search(int coursecode, tree* root){
        if (root  == NULL) {
                cout<< "COURSE NOT FOUND! "<<endl;
                return root;
        } else if( root->coursecode == coursecode) {
                return root;
        }
        else if( coursecode > root->coursecode) {
                search(coursecode, root->right);
        } else if (coursecode < root->coursecode) {
                search(coursecode, root->left);
        }

}

void tree::display(tree* root){
        if ( root == NULL) return;
        display( root->left);
        cout << root->coursecode << "\t" << endl;
        display(root->right);
}

tree* tree::min(tree* root){
        while( root->left != NULL) {
                root = root->left;
        }
        return root;
}

void tree::max(tree* root){
        while( root->right != NULL) {
                root = root->right;
        }
        cout<< endl;
        cout<< "The max is: "<< root->coursecode;
}

int tree::height(tree* root ){
        // base case
        if (root == NULL) {
                return -1;
        }
        else{
                int ldepth = height(root->left);
                int rdepth = height(root->right);

                if (ldepth > rdepth) {
                        return (ldepth + 1);
                } else return (rdepth + 1);
        }
}
int main(){

        tree* root = NULL;
        tree course;
        int x;
        do{
          cout << "1. Insert Course" << "\n" << "2. Insert Student "<< "\n" << "3. Display Courses "<< "\n"<< "4. Display Student "<< "\n" << "5. Remove course "<< "\n"<< "6. Remove student "<< "\n"<< "7. exit "<< "\n";
          cin >> x;
          switch (x) {
            // Insert course
            case 1:{
              int code;
              cout << "Please enter the course code: " << endl;
              cin >> code;
              root = course.insert(code, root);
              getch();
              system("cls");
              break;
            }
            // insert students
            case 2:{
              int code, regNum;
              cout<< "Enter the course code for student insertion: " << endl;
              cin >> code;
              cout << "Enter student's Registration number: " << endl;
              cin >> regNum;
              course.studentInsert(code, regNum, root);
              getch();
            	system("cls");
              break;
            }
            // display courses
            case 3:{
              course.display(root);
              getch();
               system("cls");
              break;
            }
            // display students:
            case 4:{
              int code;
              cout << "Enter the coursecode: "<<endl;
              cin >> code;
              course.studentDisplay(code, root);
              getch();
               system("cls");
              break;
            }
            // remove course
            case 5:{
              int code1;
              cout<< "Enter coursecode that you want to delete: "<<endl;
              cin >> code1;
              root = course.remove(root, code1);
              getch();
               system("cls");
              break;
            }
            // remove student
            case 6:{
              int code2, reg;
              cout << "Enter the coursecode " << endl;
              cin >> code2;
              cout << "Enter the registration number " << endl;
              cin >> reg;
              course.studentRemove(code2, reg, root);
              getch();
               system("cls");
              break;
            }

          }
        }while(x != 7);

        return 0;

}
