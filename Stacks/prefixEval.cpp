#include<iostream>
#include<cstring>
using namespace std;
class node{
  private:
  int data;
  node* next;

  public:
  node* head;
  node();
  void push(int);
  void pop();
  int top();
  void evalPostfix(string);
  bool isOperand(char);
  bool isOperator(char);
  int calculate(int, int, char);
  ~node(){
    node* temp = this -> head;
    while (temp) {
      this -> head = this -> head -> next;
      delete temp;
    }
  }
};

node::node(){
  this -> head = NULL;
}

void node::push(int data){
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

int node::top(){
  if ( this -> head){
  return this -> head -> data;
} else{
  return -1;
}
}

void node::evalPostfix(string expp){

  int length = expp.length();
  node stack;
  for (int i = length-1; i >= 0; i--) {

     if(expp[i] == ' ' || expp[i] == ',') continue;
    else if( this -> isOperand(expp[i])){
      int operand = 0, j = 1;
      while (i >= 0 && this -> isOperand(expp[i])) {
        operand +=  (expp[i]-'0')*j;
        j *= 10;
        i--;

      }

      i++;

       stack.push(operand);

    } else if (this -> isOperator(expp[i])){
      int op1, op2;
      op1 = stack.top();
      stack.pop();
      op2 = stack.top();
      stack.pop();
      stack.push(this -> calculate(op1, op2, expp[i]));

    }
  }

  cout<< stack.top();


}

bool node::isOperand(char x){
  if (x>='0' && x<= '9') {
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

int node:: calculate(int opr1, int opr2, char op){

  switch (op) {
    case '+':
    return opr1 + opr2;
    break;
    case '-':
    return opr1 - opr2;
    break;
    case '/':
    return opr1 / opr2;
    break;
    case '*':
    return opr1 * opr2;
    break;
  }
  return 0;
}

int main(){
  node stack;

  string expp = "- * 9 3 / 50 2";
  stack.evalPostfix(expp);


}
