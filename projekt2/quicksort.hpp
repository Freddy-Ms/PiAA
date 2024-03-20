#include<iostream>
using namespace std;

class quicksort{
    private:
        int *arr;
        int size;
    public:
        quicksort(int);
        void quickSort(int arr[], int left, int right);
        void printArray();
        void readcsv(int);
        void readcsv();
        void average();
        void median();      
};