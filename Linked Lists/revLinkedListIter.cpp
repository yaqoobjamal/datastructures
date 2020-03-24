#include<iostream>
using namespace std;
struct node{
  int data;
  node* next;
};
void insert(int);
void print();
void reverse();
node* head = NULL;
int main()
{
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  print();
  reverse();
  std::cout << '\n';
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

void reverse(){
  node *prev, *current, *next;
  current = head;
  prev = NULL;
  while (current != NULL) {
    /* code */
    next = current->next;
    current ->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}
