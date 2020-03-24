#include<iostream>
using namespace std;
#define max 100
class node{
  private:
  int top;
  int array[max];
  public:
  node();
  void push(int);
  void pop();
  int getTop();
};

node::node(){
  this -> top = -1;
}

void node::push(int data){
  if (this -> top == max - 1) {
    cout<< "Stack overflow! "<<endl;
  } else{
    array[++top] = data;
  }
}

void node::pop(){
  if (this -> top == -1) {
    cout<< "The stack is empty! "<<endl;

  } else{
    top--;
  }
}

int node::getTop(){
  if (this -> top == -1) {
    cout<< "The stack is empty! "<<endl;

  } else{
    return array[top];
  }
}
int main(){
  node stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  std::cout << stack.getTop() << '\n';
  stack.pop();
  std::cout << stack.getTop() << '\n';
}
