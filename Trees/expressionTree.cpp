#include<iostream>
#include<stack>
#include<string>
using namespace std;

class tree{
  private:
    char data;
    tree* left;
    tree* right;
  public:
  tree* insert(string);
  tree* newNode(char);
  void display(tree*);
  bool isOperand(char);
  bool isOperator(char);
};

void tree::display(tree* root){
  if(root == NULL){
    return;
  }
  display(root -> left);
  cout << root -> data << " ";
  display(root -> right);
}

bool tree::isOperand(char x){
  if (x>='a' && x<= 'z') {
    return true;
  } else{
    return false;
  }
}

bool tree::isOperator(char x){
  if( x == '+' || x == '-' || x == '*' || x == '/' ){
    return true;
  } else {
    return false;
  }
}

tree* tree::newNode(char data){
  tree* temp = new tree();
  temp -> data = data;
  temp -> left = NULL;
  temp -> right = NULL;
  return temp;
}

tree* tree::insert(string data){
  stack <tree*> s;
  for (int i = 0; i < data.length(); i++) {
    if (data[i] == ' ') continue;
    if (this -> isOperand(data[i])) {

      tree* temp = newNode(data[i]);
      s.push(temp);

    } else if(this -> isOperator(data[i])){
      tree* temp = newNode(data[i]);

      tree* t1 = s.top();
      s.pop();
      tree* t2 = s.top();
      s.pop();

      temp -> right = t1;
      temp -> left = t2;

      s.push(temp);
    }
  }
  tree* x = s.top();
  return x;
}
int main(){
  string data = "a b * c +";
  tree expression;
  tree* root = NULL;
  root = expression.insert(data);
  expression.display(root);
}
