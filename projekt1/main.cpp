#include <iostream>
#include "HQueue.cpp"
using namespace std;


const int n = 7;
int main()
{
    PriorityQueue Q(n);
    Q.generate_mssg(n);
    Q.show(); cout << endl;
    Q.make_heap();
    Q.show(); cout << endl; 
    Q.heap_sort();
    Q.show();
}