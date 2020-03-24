#include<iostream>
using namespace std;
class node{
  private:
    int data;
    node* next;
  public:
    node* head;
    node();
    void insert(int);
    void print();
    ~node(){
       node* temp = this -> head;
       while(temp){
         this -> head = this -> head -> next;
         delete temp;
       }
    }
};

node:: node(){
 this-> head = NULL;
 //cout << "Constructor called" << endl;
}

void node::insert( int data ){
  node* temp = new node();
  temp -> data = data;
  temp -> next = NULL;
  if (this-> head == NULL) {
    /* code */
    this -> head = temp;
  } else{
    node* temp1 = this -> head;
    while(temp1->next){
      temp1 = temp1 -> next;
    }
    temp1 -> next = temp;
  }
}

void node::print(){
  node* temp = this -> head;
  while(temp){
    cout<< temp -> data <<"\t";
    temp = temp -> next;
  }
}

int main(){
  node list;

  // list.insert(1);
  // list.insert(2);
  // list.insert(3);
  // // list.print();
  // node list2;
  // list2.insert(5);
  // list2.insert(5);
  // list2.insert(6);
  // list2.print();
  // list.print();
}
