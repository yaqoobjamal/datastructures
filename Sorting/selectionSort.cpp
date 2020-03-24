#include<iostream>
using namespace std;

void selectionSort(int[], int);
void swap(int[], int, int);
void print(int[], int);

int main(){
  int A[] = {9, -1, 8, 4, 3, 111};
  print(A, 6);
  selectionSort(A, 6);
  print(A, 6);
}

void selectionSort(int A[], int size){
  int min;
  for (int i = 0; i < size-1; i++) {
    min = i;
    for (int j = i + 1; j < size; j++) {
      if (A[j] < A[min]) {
        min = j;
      }
    }

    swap(A, min, i);
  }
}

void swap(int A[], int min, int i){
  int temp;
  temp = A[min];
  A[min] = A[i];
  A[i] = temp;
}

void print(int A[], int size){
  for (int i = 0; i < size; i++) {
    cout<< A[i]<<"\t";
  }
  cout << endl;
}
