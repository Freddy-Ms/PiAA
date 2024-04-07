#include <iostream>
#include "HQueue.cpp"
#include<chrono>
using namespace std;


const int n = 10000000;
int main()
{
    PriorityQueue Q(n);
    Q.generate_mssg_sorted(n);
    auto start = chrono::high_resolution_clock::now();
    Q.make_heap();
    Q.heap_sort();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    double time_taken = elapsed.count();
    cout << "Time taken by function: " << time_taken << " seconds" << endl;
    Q.show();
}