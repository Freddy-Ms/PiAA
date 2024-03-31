#include<iostream>
#include<cstddef>
#pragma once
using namespace std;


template <typename T>
class Sort
{
    private:
        T *arr;
        size_t size;
        void ReadCSV();
        void ReadCSV(int);
        void merge(int left, int middle, int right);
        friend class Quicksort;
    public:
        Sort(); // default constructor used with ReadCSV() to get all the data from the csv file
        Sort(size_t); // constructor used with ReadCSV(int) to get the first n data from the csv file
        ~Sort(); // destructor
        void clearArray(); // clear the array from -1 values
        int getlines(); // get the number of lines in the csv file
        void printArray(); // print the array
        int getsize(); // get the size of the array
        double median(); // get the median of the array
        double average(); // get the average of the array
        void quickSort(int left = 0, int right = -1); // quicksort algorithm
        void bucketSort(); // bucket sort algorithm
        void mergeSort(int left = 0, int right = -1); // merge sort algorithm
        void shuffle(); // shuffle the array
};