#include<iostream>
#include<string>
using namespace std;
class node{
  private:
  string data;
  node* next;
  public:
  node* head;
  node();
  void push(string);
  void pop();
  string top();
  string postfixToInfix(string);
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

void node::push(string data){
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

string node::top(){
  if ( this -> head){
  return this -> head -> data;
} else{
  cout<< "Stack is empty! "<<endl;
}
}

string node::postfixToInfix(string str){
  node stack;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      string temp;
      temp += str[i];
      stack.push(temp);
      temp = "\0";
    }
    if (str[i]=='+' or str[i]=='-' or str[i]=='*' or str[i]=='/')
    {
      string b = stack.top();
      stack.pop();
      string a = stack.top();
      stack.pop();
      string infix;
      infix = "(" + a + str[i] + b + ")";
      stack.push(infix);
    }
  }

  return stack.top();
}

int main(){
  string str = "A B + C D + *";
  node x;
  cout<< x.postfixToInfix(str);
}
