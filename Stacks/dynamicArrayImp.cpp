#include<iostream>
using namespace std;
class node{
  public:
  int* array;
  int top;
  node();
  void push(int);
  void pop();
  int gettop();
  bool isEmpty();

};

node::node(){
  this -> array = NULL;
  this -> top = -1;
}

void node::push(int data){

    int* temp = array;
    array = new int[++top+1];
    for (int i = 0; i < top; i++) {
      array[i] = temp[i];
    }
    array[top] = data;
    delete temp;
}

int node::gettop(){
  if (!isEmpty()) {
    return array[top];
  } else{
    cout<< "Stack is empty"<<endl;
  }

}

bool node::isEmpty(){
  return top == -1;
}

void node::pop(){
  if (!isEmpty()) {
    this -> top--;
  } else {
    cout<< "Stack is empty"<<endl;
  }

}

int main(){
  node stack;
   stack.push(1);
   stack.push(2);
   stack.push(3);
   stack.pop();
   stack.pop();
  cout<< stack.gettop();
}
