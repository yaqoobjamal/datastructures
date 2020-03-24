#include<iostream>
using namespace std;

struct node {
        int data;
        node* next;
};

void insertHead(int);
void insertHead2(int);
void mergeList();
void printBeforeMerge();
void printAfterMerge();

node* head = NULL;
node* head2 = NULL;

int main(){

  insertHead(1);
  insertHead(2);
  insertHead(3);
  insertHead2(4);
  insertHead2(5);
  insertHead2(6);
  printBeforeMerge();
  mergeList();
  printAfterMerge();

}

void insertHead(int number){
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

void insertHead2(int number){
  // Creating a node
  node* temp = new node();
  temp->data = number;
  temp->next = NULL;
  if (head2 != NULL) {
    node* temp1 = head2;
    while (temp1->next != NULL)
    {
      temp1 = temp1->next;
    }
    temp1 -> next = temp;
  } else{
    head2 = temp;
  }
}

void mergeList(){
  node* temp = head;
  while (temp -> next != NULL) {
    temp = temp -> next;
  }

  temp -> next = head2;

}

void printBeforeMerge(){
  node* temp = head;
        while (temp != NULL) {
                std::cout << temp->data << '\t';
                temp = temp->next;
        }
      cout<< "\n";
        temp = head2;
              while (temp != NULL) {
                      std::cout << temp->data << '\t';
                      temp = temp->next;
              }


}

void printAfterMerge(){
  node* temp = head;
  cout<<"\n \n";
        while (temp != NULL) {
                std::cout << temp->data << '\t';
                temp = temp->next;
        }

}
