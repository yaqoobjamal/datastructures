#include<iostream>
using namespace std;
class node{
  private:
    int data;
    node* next;
  public:
    node* front;
    node* rear;
  node();
  void enqueue(int);
  void dequeue();
  int head();
  void isEmpty();
  void print();
};

node:: node(){
  this -> front = NULL;
  this -> rear = NULL;
}

void node::enqueue(int data){
  node* temp = new node();
  temp -> data = data;
  temp -> next = NULL;
  if (this -> front == NULL) {
    this -> front = temp;
    this -> rear = temp;
  } else{
    this -> rear -> next = temp;
    this -> rear = temp;
  }


}

void node::dequeue(){
  if( this -> front){
  node * temp = this -> front;
  this -> front = this -> front -> next;
  delete temp;
} else{
  cout<< "Queue is empty!"<<endl;
}

}

int node::head(){
  return this -> front -> data;
}

void node::print(){
  node * temp = this -> front;
  while (temp){
    std::cout << temp -> data << '\t';
    temp = temp -> next;
  }
}

int main(){
  node queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  cout<< queue.head()<<endl;
  queue.dequeue();
  cout<< queue.head()<<endl;


}
