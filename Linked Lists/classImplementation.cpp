#include <iostream>
using namespace std;

class List{
    private:
       struct node{
           int val;
           node *next;
       };
         node *Head;
    public:
        List();
        void insert(int);
        void display();
        void search(int);
        void deleteNode(int);
          ~List()
          {
              node *temp;
              while(temp)
              {
                  temp = this->Head;
                  this->Head = this->Head->next;
                  delete temp;
              }
          }
};


List::List()
{
    this->Head = NULL;
}

void List::insert(int val)
{
    node *newPtr = new node(), *temp = this->Head;
    newPtr->val = val;
    newPtr->next = NULL;
    if(!this->Head)
    {
        this->Head = newPtr;
        return;
    }
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newPtr;
    return;

}

void List::display()
{
    node *temp = this->Head;
    while(temp)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    return;
}

void List::deleteNode(int val)
{
    node *curr = this->Head, *prev = NULL;
    while(curr && curr->val != val)
    {
        prev = curr;
        curr = curr->next;
    }
    if(!curr)
    {
        cout << "Cannot Delete.\n";
        return;
    }
    if(curr == this->Head)
    {
        this->Head = this->Head->next;
    }
    else
        prev->next = curr->next;
    delete curr;

}



int main()
{
 
}
