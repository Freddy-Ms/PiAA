#include "Sort.hpp"
#include <iostream>
#include <fstream>
using namespace std;
template <class T>
Sort<T>::Sort(int customSize){
    if(size == -1){
        this->size = 0;
        readcsv(-1);
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
        this->size = customSize;
    }
    arr = new T[size];
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
}
