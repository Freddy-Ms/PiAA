#include<iostream>
#include<fstream>
#include <algorithm> 
#include<vector>
#include<random>
#include<string>
#include<sstream>
using namespace std;
#include"Sort.hpp"

template <typename T>
int Sort<T>::getlines()
{
    int lines = 0;
    ifstream file("projekt2_dane.csv");
    if (!file.is_open()){
        cout << "Error opening file" <<  endl;
        return 0;
    }
    string line,token;
    while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::getline(ss, token, ','); 
    std::getline(ss, token, ','); 
    std::getline(ss, token, ','); 
    bool poprawnaOcena = true;
    try {
        double ocena = std::stod(token);
    } catch (const std::invalid_argument& e) {
        poprawnaOcena = false;
    }
    if (!token.empty() && poprawnaOcena) 
        ++lines;

}
    file.clear();
    file.seekg(0);
    return lines;
}

template <typename T>
Sort<T>::Sort()
{
    this->size = getlines();
    this->arr = new T[this->size];
    ReadCSV();
}

template <typename T>
Sort<T>::Sort(size_t customSize){
    this->size = customSize;
    this->arr = new T[this->size];
    ReadCSV();
}

template <typename T>
void Sort<T>::ReadCSV()
{
    ifstream file("projekt2_dane.csv");
    if (!file.is_open()){
        cout << "Error opening file" <<  endl;
        return;
    }
    string dummy, data;
    for (int i = 0; i < this->size; i++){
        getline(file, dummy, ',');
        getline(file, dummy, ',');
        getline(file, data);
        try{
            this->arr[i] = stoi(data);
        } catch(const invalid_argument& e){
            i--;
        }
    }
    file.close();
}
template <typename T>
Sort<T>::~Sort()
{
    delete[] arr;
}
template <typename T>
int Sort<T>::getsize()
{
    return size;
}
template <typename T>
double Sort<T>::median()
{
    if(size % 2 == 0)
        return (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
    else
        return arr[size / 2];
}
template <typename T>
double Sort<T>::average()
{
    double sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}
template <typename T>
void Sort<T>::printArray()
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

template <typename T>
void Sort<T>::quickSort(int left, int right){
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
template <typename T>
void Sort<T>::mergeSort(int left, int right){
    if (right == -1)
        right = size - 1;
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(left, middle);
        mergeSort(middle + 1, right);
        merge(left, middle, right);
    }
}
template <typename T>
void Sort<T>::merge(int left, int middle, int right){
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    T* L = new T[n1]; 
    T* R = new T[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];
    i = 0;         // Index of left array
    j = 0;          // Index of right array
    k = left;       // Index of main array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}
template<typename T>
void Sort<T>::bucketSort() {
    T max_val = arr[0], min_val = arr[0];
    for (int i =  1; i < size; ++i) {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }

    int num_buckets = 10;
    int range = max_val - min_val + 1;

    vector<T>* buckets = new vector<T>[num_buckets];

    for (int i = 0; i < size; ++i) {
        buckets[(arr[i] - min_val) * num_buckets / range].push_back(arr[i]);
    }

    int index = 0;
    for (int i = 0; i < num_buckets; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
        for (T element : buckets[i]) {
            arr[index++] = element;
        }
    }
    delete[] buckets;
}
template<typename T>
void Sort<T>::shuffle() {
    for (int i = 0; i < size; ++i) {
        int random_index = rand() % size;
        swap(arr[i], arr[random_index]);
    }
}