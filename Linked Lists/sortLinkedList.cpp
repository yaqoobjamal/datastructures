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
  insert(4);
  insert(3);
  insert(2);
  insert(1);
  print();
  sortList();
  cout<<"\n \n";
  cout<<"After sorting: "<<"\n"<<endl;
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
  int temp;
  for (node* i = head; i -> next!=NULL; i = i -> next) {
    for (node* j = i-> next; j!=NULL; j = j->next) {
      if (i-> data > j-> data) {
        temp = j-> data;
        j -> data = i -> data;
        i -> data = temp;
      }
    }
  }
  // node* temp = head;
  // int n = 0, tmp; // Counting the number of nodes
  //       while (temp != NULL) {
  //               n++;
  //               temp = temp->next;
  //       }
  //   //    temp = head;
  //
  //     for (int i = 0; i < n-1 ; i++) {
  //       temp = head;
  //       for (int j = 0; j < n-i-1; j++) {
  //         if (temp-> data > temp -> next -> data) {
  //           tmp = temp-> data;
  //           temp-> data = temp -> next -> data;
  //           temp -> next -> data = tmp;
  //
  //         }
  //         temp = temp -> next;
  //       }
  //     }
}

void print(){
  node* temp = head;
        while (temp != NULL) {
                std::cout << temp->data << '\t';
                temp = temp->next;
        }

}
