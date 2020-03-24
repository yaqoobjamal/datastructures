#include<iostream>
using namespace std; // recursion
struct node{
  int data;
  node* next;
};
void insert(int);
void print();
void reverse(node*);
node* head = NULL;
int main(){
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  print();
  reverse(head);
  std::cout <<  '\n';
  print();
}

void insert(int num){
  node* temp = new node();
  temp->data = num;
  temp->next = head;
  head = temp;

}

void print(){
  node* temp1 = head;
  while( temp1 != NULL)
  {
    std::cout << temp1->data << '\t';
    temp1 = temp1->next;
  }
}

void reverse(node* temp){
  if (temp -> next == NULL) {
    /* code */
    head = temp;
    return;
  }
  reverse(temp -> next);
  node* temp1 = temp -> next;
  temp1 -> next = temp;
  temp -> next = NULL;
}
