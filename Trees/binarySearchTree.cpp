#include<iostream>
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
};

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
  } else{
    root -> right = insert(data, root -> right);
  }
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
  // int num;
  // ifstream inFile;
  // ofstream outFile;
  // outFile.open("bstOut.txt");
  // inFile.open("bst.txt");
  // tree* root = NULL;
  // tree BST;
  // while (inFile >> num) {
  //   root = BST.insert(num, root);
  // }
  //
  // BST.display(root);
  tree* root = NULL;
  tree BST;
  root =  BST.insert(43, root);
	BST.insert(15, root);
	BST.insert(60, root);
	BST.insert(8, root);
	BST.insert(30, root);
	BST.insert(20, root);
	BST.insert(35, root);
	BST.insert(50, root);
	BST.insert(82, root);
	BST.insert(70, root);
  BST.remove(root, 43);
  BST.remove(root, 35);
  BST.display(root);

}
