#include <iostream>
using namespace std;
struct node{
  int data;
  node* next;
  node* prev;
};

void insertAtHead(int );
void print();
void revPrint();
node* head = NULL;

int main(){
  insertAtHead(1);
  insertAtHead(2);
  insertAtHead(3);
  insertAtHead(4);
  insertAtHead(5);
  insertAtHead(6);
  insertAtHead(7);
  insertAtHead(8);
  insertAtHead(9);
  insertAtHead(10);
  print();
  std::cout << '\n';
  revPrint();


}

void insertAtHead(int num){
  node* temp = new node();
  temp -> data = num;
  temp->next = NULL;
  temp->prev = NULL;
  if ( head == NULL) {
    /* code */
    head = temp;
  } else {
    node* temp1 =  head;
    temp ->next = temp1;
    temp1 -> prev = temp;
    head = temp;

  }
}

void print(){
  node* temp2 = head;
  while(temp2 != NULL){
    std::cout << temp2 ->data << '\t';
    temp2 = temp2 -> next;
  }
}

void revPrint(){
  node* temp3 = head;
  while(temp3 ->next != NULL){
    temp3 = temp3 -> next;
  }

  while(temp3 != NULL){
    std::cout << temp3->data << '\t';
    temp3 = temp3->prev;
  }
}
