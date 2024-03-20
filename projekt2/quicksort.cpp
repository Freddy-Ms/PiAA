#include<iostream>
#include"quicksort.hpp"
using namespace std;

quicksort::quicksort(int size){
    arr = new int[size];
    this->size = size;
}
quicksort::~quicksort(){
    delete[] arr;
}
void quicksort::quickSort(int arr[], int left, int right){
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
void quicksort::printArray(){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void quicksort::readcsv(int size){
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}
void quicksort::readcsv(){
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}
void quicksort::average(){
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    cout << "Average: " << sum / size << endl;
}
void quicksort::median(){
    if(size % 2 == 0){ cout << "Median: " << arr[size / 2] << endl;}
    else{ cout << "Median: " << (arr[size / 2] + arr[size / 2 + 1]) / 2 << endl;}
}