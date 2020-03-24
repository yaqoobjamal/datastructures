#include<iostream>
using namespace std;
struct node {
        int data;
        node* next;
};
void insert(int);
void sortList();
void print();

node* head = NULL;
int main(){
  insert(3);
  insert(2);
  insert(1);
  print();
  sortList();
  cout<<"\n";
  print();

}

void insert(int number){ // Number insertion at the end
  // Creating a node
  node* temp = new node();
  temp->data = number;
  temp->next = NULL;
  if (head != NULL) {
    node* temp1 = head;
    while (temp1->next != NULL)
    {
      temp1 = temp1->next;
    }
    temp1 -> next = temp;
  } else{
    head = temp;
  }
}

void sortList(){
  for(node *temp1 = head;temp1 != NULL;temp1=temp1->next)
  {
    for(node *temp2 = temp1->next;temp2 != NULL;temp2 = temp2->next)
    {
      if(temp1->data > temp2->data)
      {
        int c = temp1->data;
        temp1->data = temp2->data;
        temp2->data = c;
      }
    }
  }
}

void print(){
  node* temp = head;
        while (temp != NULL) {
                std::cout << temp->data << '\t';
                temp = temp->next;
        }

}
