#pragma once
#include<iostream>
#include<cstddef>
#include"Sort.cpp"
using namespace std;

template <typename T>
class Quicksort: public Sort<T>{
    public:
        using Sort<T>::Sort;
        ~Quicksort(){}
        void quickSort(int left = 0, int right = -1);
};


template <typename T>
void Quicksort<T>::quickSort(int left , int right ){
            if (right == -1)
                right = this->size - 1;
            int i = left, j = right;
            int pivot = this->arr[(left + right) / 2];
            while (i <= j) {
                while (this->arr[i] < pivot)
                    i++;
                while (this->arr[j] > pivot)
                    j--;
                if (i <= j) {
                    swap(this->arr[i], this->arr[j]);
                    i++;
                    j--;
                }
            }
            if (left < j)
                this->quickSort(left, j);
            if (i < right)
                this->quickSort(i, right);
}