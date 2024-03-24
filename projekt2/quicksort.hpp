#include<iostream>
using namespace std;

class quicksort{
    private:
        int *arr;
        int size;
    public:
        quicksort(int); // Określona liczba elementów połączona z readcsv(int)
        void readcsv(int);
        ~quicksort();
        void quickSort(int, int); // Służy do uruchomienia funckji, która następnie używa funkcji niżej, aby podzielić odpowiednio tablicę
        void printArray();
        void cleararray(); // Czyści tablicę z -1 -> wartość wpisywana kiedy nie ma rankingu 
        void average();
        void median();      
};