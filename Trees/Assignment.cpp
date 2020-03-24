#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class tree{
  private:
    tree* left;
    tree* right;
    string name;
    string faculty;
    int reg;

  public:
    tree* insert(int, string, string, tree*);
    void search(int, tree*);
    void display(tree*);
    void preDisplay();
    tree* min(tree*);
    void max(tree*);
    int height(tree*);
    tree* remove(tree*, int);
    tree* right_rot(tree*);
    tree* left_rot(tree*);
    tree* lr_rot(tree*);
    tree* rl_rot(tree*);
};



tree* tree::right_rot(tree* t){
  tree* u = t -> left;
  t -> left = u -> right;
  u ->right = t;
  return u;

}

tree* tree::left_rot(tree* t){
  tree* u = t -> right;
  t -> right = u -> left;
  u -> left = t;
  return u;
}

tree* tree::rl_rot(tree* t){
  t -> right = right_rot(t -> right);
  return left_rot(t);
}

tree* tree::lr_rot(tree* t){
  t -> left = left_rot( t-> left);
  return right_rot(t);
}

tree* tree::remove(tree* root, int reg){
  // base case
  if (root == NULL) {
    cout << "DATA NOT FOUND." <<endl;
    return root;
  } else if (reg > root -> reg) {
    root -> right = remove(root -> right, reg);
  } else if(reg < root -> reg){
    root -> left = remove(root -> left, reg);
  } else{
    // three cases
    // Case 1: No child
    if(root -> left == NULL && root -> right == NULL){
      delete root;
      root = NULL;
    }

    // Case 2: One child
    else if(root -> left == NULL){
      tree* temp = root;
      root = root -> right;
      delete temp;

    } else if(root -> right == NULL){
      tree* temp = root;
      root = root -> left;
      delete temp;
    } else { // Case 3: Two children
      tree* temp = min(root -> right);
      root -> reg = temp -> reg;
      root -> right = remove(root -> right, temp -> reg);
    }

  }


  return root;
}

tree* tree::insert(int reg, string name, string faculty, tree* root){
  if ( root == NULL) {
    tree* temp = new tree();
    temp -> reg = reg;
    temp -> name = name;
    temp -> faculty = faculty;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
  } else if( reg < root -> reg){
    root -> left = insert(reg, name, faculty, root-> left);
    if (height(root -> left) - height(root -> right) == 2) {
      if ( reg < root -> left -> reg) {
        root = right_rot(root);
      } else root =  lr_rot(root);
    }
  } else{
    root -> right = insert(reg, name, faculty, root -> right);
    if (height(root -> right) - height(root -> left) == 2) {
      if (reg > root -> right -> reg ) {
        root = left_rot(root);
      } else root = rl_rot(root);
    }
  }
  return root;
}

void tree::search(int reg, tree* root){
  if (root  == NULL) {
    cout<< "DATA NOT FOUND! "<<endl;
    return;
  } else if( root -> reg == reg){
    cout<<" DATA FOUND"<<endl;
    return;
  }
   else if( reg > root -> reg){
    search(reg, root -> right);
  } else if (reg < root -> reg){
    search(reg, root -> left);
  }

}

void tree::preDisplay(){
  cout << "Reg # " << setw(15) << "Name "<< setw(15) << "Faculty " << setw(15) << "Height " << endl;
}

void tree::display(tree* root){
  if ( root == NULL) return;
  display( root -> left);
  cout << root -> reg << setw(15)<< root -> name << setw(10)<< root -> faculty << setw(15)<<height(root)<<endl;
  display(root -> right);
}

tree* tree::min(tree* root){
  while( root -> left != NULL){
    root = root -> left;
  }
  return root;
}

void tree::max(tree* root){
  while( root -> right != NULL){
    root = root -> right;
  }
  cout<< endl;
  cout<< "The max is: "<< root -> reg;
}

int tree::height(tree* root ){
  // base case
  if (root == NULL) {
    return -1;
  }
  else{
  int ldepth = height(root -> left);
  int rdepth = height(root -> right);

  if (ldepth > rdepth) {
    return (ldepth + 1);
  } else return (rdepth + 1);
}
}
int main(){

  tree* root = NULL;
  tree avl;
  int x;
  do {
    cout << "1. Insert" << "\n" <<"2. Remove" <<"\n" << "3. Display" <<  "\n" << "4. Exit" << endl;
    cin >> x;
    switch (x) {
      // Insert student
      case 1:
      {
        int reg;
        string name;
        string faculty;
        cout << "Enter reg: "<< endl;
        cin >> reg;
        cout << "Enter name: " << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter faculty: " << endl;
        getline(cin, faculty);
        root = avl.insert(reg, name, faculty, root);
        getch();
        system("cls");
        break;
      }
      // remove
      case 2:
      {
        int reg;
        std::cout << "Enter reg: " << '\n';
        cin >> reg;
        root = avl.remove(root, reg);
        getch();
        system("cls");
        break;
      }
      // Display
      case 3:
      {
        avl.preDisplay();
        avl.display(root);
        getch();
        system("cls");
        break;
      }
    }

  } while(x != 4);


}
