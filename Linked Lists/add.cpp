#include <iostream>
using namespace std;
struct node {
								int data;
								node* next;
};

void insertHead1(int);
void insertHead2(int);
void insertSum();
void print();
node* head1 = NULL;
node* head2 = NULL;
node* head3 = NULL;
int main(){
		insertHead1(76);
		insertHead1(-13);
		insertHead1(42);
		insertHead2(-10);
		insertHead2(55);
		insertHead2(26);
		insertSum();
		print();
}

void insertHead1(int num)
{
								// Creating a new node
								node* temp = new node();
								temp->data= num;
								temp->next = head1;
								head1 = temp;
}

void insertHead2(int num)
{
								// Creating a new node
								node* temp = new node();
								temp->data = num;
								temp->next = head2;
								head2 = temp;
}

void print(){
								node* temp1 = head1;
								node* temp2 = head2;
								node* temp3 = head3;
								// Printing list 1
								while(temp1 != NULL) {
																cout<< temp1->data<< "\t";
																temp1 = temp1->next;
								}
								cout<< "\n";
								// Printing list 2
								while(temp2 != NULL) {
																cout<< temp2->data<< "\t";
																temp2 = temp2->next;

								}
								cout<<"\n";
								// Printing list 3
								while(temp3 != NULL) {
																cout<< temp3->data<< "\t";
																temp3 = temp3->next;
								}

}
void insertSum(){
								node* temp1, *temp2;
								int sum;
								temp1 = head1;
								temp2 = head2;
								while(temp1 != NULL && temp2!= NULL) {
																sum = temp1->data + temp2->data;
																temp1 = temp1->next;
																temp2 = temp2->next;
																node* temp3 = new node();
																if( head3 == NULL) {
																								temp3->data = sum;
																								temp3->next = NULL;
																								head3 = temp3;
																} else{
																								node* temp4 = head3;
																								while( temp4->next != NULL) {
																																temp4 = temp4->next;
																								}
																								temp4->next = temp3;
																								temp3->data = sum;
																								temp3->next = NULL;
																}
								}

}
