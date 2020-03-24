#include <iostream>
using namespace std;
struct node {
        int data;
        node* next;

};
 // This is an empty list
node* insert(int, node* ); // This is a fucntion to insert data
void print(node* );
int main(){
  node* head = NULL;
  // insert(1,1); // 1
  // insert(2,1); // 2,1
  // insert(3,1); // 3,2,1
  // insert(5,2); // 3,5,2,1
  // insert(6,3); // 3,5,6,2,1
  // insert(6,4); // 3,5,6,6,2,1
  // print();

  head = insert(1, head); // Head is changed only in the first insertion
  head = insert(2, head);
  head = insert(3, head);
  head =  insert(4, head); // 4 , 3 ,2 ,1
  print(head);

}

node* insert(int number, node* head ){
  // // Creating a new node.
  // node* temp = new node();
  // temp -> data = number;
  // if (id == 1) {
  //   temp -> next = head;
  //   head = temp;
  // } else{
  //   node* temp2 = head; // Starts at the head
  //   for (int i = 0; i < id-2; i++) { // i=0 corresponds to second node, i = 1 corresponds to the third node and so on.
  //     temp2 = temp2 -> next;
  //   }
  //   temp -> next = temp2 -> next;
  //   temp2 -> next = temp;
  // }
  // Creating a node
  node* temp = new node();
  temp -> data = number;
  if ( head == NULL) {
    head = temp;
    temp -> next = NULL;
  } else{
    // Below is the code for entering data in the head
    temp -> next = head;
    head = temp;
    // This is the code for tail Data
    // node* temp1 = head;
    // while ( temp1 -> next != NULL) {
    //   temp1 = temp1 -> next;
    // }
    //
    // temp1 -> next = temp; // My last node should point to the newly created node
    // temp -> next = NULL; // Temp is our new node. Temp1 is our last node

  }
  return head;
}

void print(node* head){
  // node* temp3 = head;
  //       while (temp3 != NULL) {
  //               std::cout << temp3->data << '\t';
  //               temp3 = temp3->next;
  //       }

  node* temp = head;
  while( temp != NULL){
    std::cout << temp -> data << '\t';
    temp = temp -> next;
  }

}
