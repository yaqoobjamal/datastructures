#include<iostream>
using namespace std;
struct node{
  int data;
  node* next;

};
void insert(int);
void print();
// Step 1:
node* head = NULL;
int main(){
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  insert(5);
  print();
}

void insert(int num){
  node* temp = new node();
  temp->data = num;

  if (head != NULL) {
    temp->next = head;
    head = temp;
  } else{
    temp->next = NULL;
    head = temp;
  }
}

void print(){
  node* temp1 = head;
  while(temp1 != NULL){
    std::cout << temp1->data << '\t';
    temp1 = temp1->next;
  }
}
