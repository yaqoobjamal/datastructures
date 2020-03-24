#include <iostream>
using namespace std;
struct node {
        /* struct for a node */
        int data;  // Data Field
        node* next; // Pointer to the next node
};
node* insert(node* head, int); // Function to insert data into the node which also returns an updated head pointer.
void print(node* head); // Printing node data

int main() {
        node* head = NULL;  // Initializing head of the linked list as NULL indicating an empty list.
        int x, number;
        std::cout << "Enter the number of elements? " << '\n';
        std::cin >> x;

        for (int i = 0; i < x; i++) {
                std::cout << "Enter the number" << '\n';
                std::cin >> number;
                head = insert(head, number); // Inserting number into the node with updated head.
        }
        print(head); // Calling the print function here
        return 0;
}

node* insert(node* head, int number){
        // Step 1 is creating a new node as follows
        node* temp = new node(); // Temp is pointer to the node just made.
        temp->data = number; // Using this pointer to dereference data field and insert data into it.
        if (head != NULL) { // If the list is not empty then, newest created node should point to the one before it
                temp->next = head;
        } else {
                temp->next = NULL; // Else if empty then current made node shouldn't point to anything.
        }
        head = temp; // Head now points to latest added node
        return head; // Returning updated head.
}

// Passing head into the print function to start from head and traverse till the end of the linked list.
void print(node* head){
        while (head!=NULL ) {
                std::cout << head->data << '\t';
                head = head->next;
        }

}
