#include "Quicksortt.hpp"

template <typename T>
Quicksort<T>::Quicksort(int customSize) : Sort<T>(customSize) {}

template <typename T>
void quickSort(int left , int right ){
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
