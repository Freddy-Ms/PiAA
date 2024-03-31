#pragma once
#include<iostream>
#include <cstddef>
using namespace std;

template <class T>
class Sort{
    public:
        T *arr;
        size_t size;
        void readcsv(int customSize = -1); // Read data from csv file
    public:
        Sort(int); // Creating an array of size elements, if not given argument all data will be loaded from readcsv and the size will be set accordingly
        ~Sort();    // Delocate memory
        void printArray();  // Print the array
        double average(); // Calculate the average of the array
        double median();  // Calculate the median of the array
        friend class Quicksort;
};

/*
template <class T>
Sort<T>::Sort(int customSize){
    if(size == -1){
        this->size = 0;
        readcsv();
    } else {
        this->size = customSize;
        readcsv(this->size);
    }
}
template <typename T>
void Sort<T>::readcsv(int customSize){
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
            i--;
        }
    }
    file.close();
}
template <typename T>
void Sort<T>::printArray(){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
template <typename T>
double Sort<T>::average(){
    double sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}
template <typename T>
double Sort<T>::median(){
    if(size % 2 == 0)
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    else
        return arr[size / 2];
}
template <typename T>
Sort<T>::~Sort(){
    delete[] arr;
}*/