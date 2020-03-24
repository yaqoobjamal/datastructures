#include<iostream>
using namespace std;
struct node{
  int data;
  node* next;
};
void insert(int);
void print();
void revPrint();
node* head = NULL;
node* temp1 = head;
int main()
{
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  temp1 = head;
  print();
}

void insert(int num){
  node* temp = new node();
  temp->data = num;
  temp->next = head;
  head = temp;

}

void print(){
  if (temp1 == NULL) {
    /* code */
    return;
  }
  temp1 = temp1 ->next;
  print();
  std::cout << temp1-> data << '\n';

}
