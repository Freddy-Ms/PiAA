#include<iostream>
#include<fstream>
#include"quicksort.hpp"
using namespace std;

quicksort::quicksort(int size = 0){
    if(size < 0){
        cout << "Invalid size" << endl;
        arr = nullptr;
        size = 0;
    } else {
        arr = new int[size];
        this->size = size;
    }
}
quicksort::~quicksort(){
    delete[] arr;
}
void quicksort::quickSort(int left = 0, int right = -1){
    if (right == -1)
        right = size - 1;
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
    }
    if (left < j)
        quickSort(left, j);
    if (i < right)
        quickSort(i, right);
}

void quicksort::printArray(){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void quicksort::readcsv(int customSize = -1){
    ifstream file("projekt2_dane.csv");
    if (!file.is_open()){
        cout << "Error opening file" <<  endl;
        return;
    }
    string line;
    if(customSize == -1){
        while(getline(file, line)){
            ++size;
        }
        file.clear();
        file.seekg(0);
    } else {
        size = customSize;
    }
    arr = new int[size];
    string dummy, data;
    for (int i = 0; i < size; i++){
        getline(file, dummy, ',');
        getline(file, dummy, ',');
        getline(file, data);
        try{
            arr[i] = stoi(data);
        } catch(const invalid_argument& e){
            cout << "Invalid argument" << endl;
            arr[i] = -1;
        }
    }
    file.close();
}
void quicksort::cleararray(){
    int space = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == -1) {
            space++;
        } else {
            arr[i - space] = arr[i];
        }
    }
    size -= space;
}
void quicksort::average(){
    double sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    cout << "Average: " << sum / size << endl;
}
void quicksort::median(){
    if(size % 2 == 0){ cout << "Median: " << arr[size / 2] << endl;}
    else{ cout << "Median: " << double((arr[size / 2] + arr[size / 2 + 1])) / 2 << endl;}
}