#include<iostream>
using namespace std;
class node{
  private:
  int* array;
  int used;
  public:
  node();
  void insert(int);
  void print();
  void find();
  void remove();
};

node::node(){
  this -> array = NULL;
  this -> used = -1;
}

void node::insert(int data){
  int* temp = array;
  array = new int[++used+1]; // used = 2 // array 3
  for (int i = 0; i < used; i++) { // used = 2
    array[i] = temp[i];
  }
  delete temp;
  if (used != 0) {
    for (int i = used; i > 0; i--) { // used = 0
      array[i] = array[i-1];
    } // Shifts all elements towards right
    array[0] = data;
  } else{
    array[used] = data;
  }



}

void node::print(){
  for (int i = 0; i <= used; i++) {
    std::cout << array[i] << '\t';
  }
}

void node::remove(){
  used--;
}

int main(){
  cout << "This is a pull request. "<< endl;
}
