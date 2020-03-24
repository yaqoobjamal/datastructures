#include<iostream>
#include<string>
using namespace std;
class node{
  private:
  char data;
  node* next;
  public:
  node* head;
  node();
  void push(char);
  void pop();
  char top();
  int prec(char); // returns precidence
  bool highPrecedence(char, char);
  string infixToPostfix(string);
  bool isOperand(char);
  bool isOperator(char);
  bool isOpenBrace(char);
  bool isCloseBrace(char);
  bool isEmpty();
};

node::node(){
  this -> head = NULL;
}

bool node::isEmpty(){
  if (this -> head == NULL) {
    return true;
  } else{
    return false;
  }
}

void node::push(char data){
  node* temp = new node();
  temp -> data = data;
  temp -> next = this -> head;
  this -> head = temp;
}

void node::pop(){
  if ( this -> head) {
    node* temp = this -> head;
    this -> head = this -> head -> next;
    delete temp;
  } else{
    cout<< "Nothing to pop!"<<endl;
  }

}

char node::top(){
  if ( this -> head){
  return this -> head -> data;
} else{
  return -1;
}
}

int node:: prec(char x){
  switch (x) {
    case '+':
    return 1;
    case '-':
    return 1;
    case '*':
    return 2;
    case '/':
    return 2;
  }
}

bool node::highPrecedence(char a, char b){
  int top = prec(a);
  int cur = prec(b);
  if (top >= cur ) {
    return true;
  } else {
    return false;
  }
}

string node::infixToPostfix(string expp){
  int length = expp.length();
  node stack;
  string infix = "";
  for (int i = 0; i < length; i++) {
    if(expp[i] == ' ' || expp[i] == ',') continue;
    if (this -> isOperand(expp[i])) {
      infix += expp[i];
      infix += " ";
    } else if(this -> isOperator(expp[i])){
      while( !stack.isEmpty() && this -> highPrecedence(stack.top(), expp[i]) && !this -> isOpenBrace(stack.top())){
        infix += stack.top();
        infix += " ";
        stack.pop();
      }
       stack.push(expp[i]);

    }

     else if (this -> isOpenBrace(expp[i])) {
       stack.push(expp[i]);
     }
      else if(this -> isCloseBrace(expp[i])){
        while (!stack.isEmpty() && !this ->isOpenBrace(stack.top())) {
          infix += stack.top();
          infix += " ";
          stack.pop();
        }
        stack.pop();
      }

  }
    while(!stack.isEmpty()){
      infix += stack.top();
      infix += " ";
      stack.pop();
    }

    return infix;
}

bool node::isOperand(char x){
  if ( (x >= 'A' && x <= 'Z') || (x >= '0' && x <= '9') ) {
    return true;
  } else{
    return false;
  }
}

bool node::isOperator(char x){
  if( x == '+' || x == '-' || x == '*' || x == '/' ){
    return true;
  } else {
    return false;
  }
}

bool node::isOpenBrace(char x){
  if ( x == '(') {
    return true;
  } else {
    return false;
  }
}

bool node::isCloseBrace(char x){
  if ( x == ')') {
    return true;
  } else {
    return false;
  }
}

int main(){
  string expp = "(A + B) * (C + D)";
  node x;
  cout << x.infixToPostfix(expp);

}
