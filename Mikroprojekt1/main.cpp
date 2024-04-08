#include <iostream>
#include "HQueue.cpp"
#include<chrono>
using namespace std;


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    PriorityQueue* Q = new PriorityQueue(n); 
    cout << "The elements are: \n";
    cout << "1. Random\n2. Sorted\n";
    int choice;
    cin >> choice;
    if(choice == 2)
        Q->generate_mssg_sorted(n);
    else
        Q->generate_mssg(n);
    auto start = chrono::high_resolution_clock::now();
    Q->make_heap();
    Q->heap_sort();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    double time_taken = elapsed.count();
    cout << "Time taken by function: " << time_taken << " seconds" << endl;
    delete Q; 
    return 0;
}