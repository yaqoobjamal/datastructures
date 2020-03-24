#include<iostream>
using namespace std;

void merge(int[], int);
void mergeSort(int[], int);
void print(int[], int);
int main(){
  int A[] = {2, 4, 1, 6, 8, 5, 3, 7};
  int nA = sizeof(A)/sizeof(*A);
  print(A, nA);
  mergeSort(A, nA);
  print(A, nA);

}

void mergeSort(int A[],int nA){

  int mid = nA / 2;
  int nL = mid;
  int nR = nA - nL;
  // base case
  if (nL == 0 || nR == 0) {
    return;
  }
  int* l = new int[nL];
  int* r = new int[nR];

  for (int i = 0; i < nL; i++) {
    l[i] = A[i];
  }

  for (int i = 0; i < nR; i++) {
    r[i] = A[nL + i];
  }
  mergeSort(l, nL);
  mergeSort(r, nR);
  merge(A, nA);
}

void merge(int A[], int nA){
  int mid = nA / 2;
  int nL = mid;
  int nR = nA - nL;
  int* l = new int[nL];
  int* r = new int[nR];

  for (int i = 0; i < nL; i++) {
    l[i] = A[i];
  }

  for (int i = 0; i < nR; i++) {
    r[i] = A[nL + i];
  }

  int i = 0, j = 0, k = 0;

  while (i < nL && j < nR) {
    if (l[i] <= r[j] ) {
      A[k] = l[i];
      i++;
    } else {
      A[k] = r[j];
      j++;

    }
    k++;
  }

  while(i < nL){
    A[k] = l[i];
    i++;
    k++;
  }
  while(j < nR){
    A[k] = r[j];
    j++;
    k++;
  }

}

void print(int A[], int size){
  for (int i = 0; i < size; i++) {
    cout<< A[i]<<"\t";
  }
  cout << endl;
}
