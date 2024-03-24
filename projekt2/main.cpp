#include <iostream>
using namespace std;
#include "quicksort.cpp"

int main(){
    quicksort q(10);
    q.readcsv(10);
    q.quickSort();
    q.average();
    q.median();
    q.printArray();
    return 0;
}
