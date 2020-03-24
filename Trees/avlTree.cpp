#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

class tree{
  private:
    tree* left;
    tree* right;
    int data;

  public:
    tree* insert(int, tree*);
    void search(int, tree*);
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
        std::cout<< p->data << "\n ";
        if(p->left) {
            std::cout << std::setw(indent) << ' ' <<" \\\n";
            prettyPrint(p->left, indent+4);
        }
    }
}

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

tree* tree::remove(tree* root, int data){
  // base case
  if (root == NULL) {
    cout << "DATA NOT FOUND." <<endl;
    return root;
  } else if (data > root -> data) {
    root -> right = remove(root -> right, data);
  } else if(data < root -> data){
    root -> left = remove(root -> left, data);
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
      root -> data = temp -> data;
      root -> right = remove(root -> right, temp -> data);
    }

  }
  return root;
}

tree* tree::insert(int data, tree* root){
  if ( root == NULL) {
    tree* temp = new tree();
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
  } else if( data < root -> data){
    root -> left = insert(data, root-> left);
    if (height(root -> left) - height(root -> right) == 2) {
      if ( data < root -> left -> data) {
        root = right_rot(root);
      } else root =  lr_rot(root);
    }
  } else{
    root -> right = insert(data, root -> right);
    if (height(root -> right) - height(root -> left) == 2) {
      if (data > root -> right -> data ) {
        root = left_rot(root);
      } else root = rl_rot(root);
    }
  }
  return root;
}

void tree::search(int data, tree* root){
  if (root  == NULL) {
    cout<< "DATA NOT FOUND! "<<endl;
    return;
  } else if( root -> data == data){
    cout<<" DATA FOUND"<<endl;
    return;
  }
   else if( data > root -> data){
    search(data, root -> right);
  } else if (data < root -> data){
    search(data, root -> left);
  }

}

void tree::display(tree* root){
  if ( root == NULL) return;
  display( root -> left);
  cout << root -> data << "\t"<<height(root)<<endl;
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
  cout<< "The max is: "<< root -> data;
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
  ifstream inFile;
  int num;
  inFile.open("avl.txt");
  while(inFile >> num){

    root = avl.insert(num, root);

  }

  inFile.close();
  avl.display(root);


}
