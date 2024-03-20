#include <iostream>
using namespace std;
class mergesort
{ private:
    int *arr;
    int size;
    int actualsize;
  public:
    mergesort(int);
    void mergeSort(int arr[], int l, int r);
    void merge(int arr[], int l, int m, int r);
    void printArray();
};