#include <iostream>
using namespace std;
struct node {
        int data;
        node* next;
};
node* head = NULL;

void insert(int);
void remove(int);
void print();

int main(){
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  print();
  remove(4); // Supply which node to delete. 
  cout<< "\n";
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

void print(){
  node* temp2 = head;
        while (temp2 != NULL) {
                std::cout << temp2->data << '\t';
                temp2 = temp2->next;
        }

}

void remove(int id){
  node* temp3 = head;
  if (id == 1) {
    head = temp3 ->next;
    delete temp3;

  }

  for (int i = 0; i < id-2; i++) {
    temp3 = temp3 -> next;
  }
  node* temp4 = temp3 ->next;
  temp3 -> next = temp4 ->next;
  delete temp4;
}
