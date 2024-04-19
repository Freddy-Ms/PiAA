#include <iostream>
#include<chrono>
#include"Sort.cpp"

int main() {
    std::cout << "Give number of elements: \n";
    std::cout << "To load all data from the file, press 0\n";
    int n;
    std::cin >> n;
    Sort<int>* s;
    chrono::high_resolution_clock::time_point start, end;
    chrono::duration<double, std::milli> elapsed;

    if (n == 0){
        start = std::chrono::high_resolution_clock::now();
        s = new Sort<int>();
        end = std::chrono::high_resolution_clock::now();
        }
    else{
        start = std::chrono::high_resolution_clock::now();
        s = new Sort<int>(n);
        end = std::chrono::high_resolution_clock::now();}

    elapsed = end - start;
    std::cout << "Time taken by function: " << elapsed.count() << " miliseconds" << std::endl;
    int choice = 0;


    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Show elements\n";
        std::cout << "2. Calculate median\n";
        std::cout << "3. Calculate average\n";
        std::cout << "4. Get size of array\n";
        std::cout << "5. Quicksort\n";
        std::cout << "6. Mergesort\n";
        std::cout << "7. Bucketsort\n";
        std::cout << "8. Shuffle\n";
        std::cout << "9. Exit\n";
        std::cout << "Choose option: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            s->printArray();
            break;
        case 2:
            std::cout << "Median: " << s->median() << std::endl;
            break;
        case 3:
            std::cout << "Average: " << s->average() << std::endl;
            break;
        case 4:
            std::cout << "Size: " << s->getsize() << std::endl;
            break;
        case 5:
            start = std::chrono::high_resolution_clock::now();
            s->quickSort();
            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            std::cout << "Time taken by function: " << elapsed.count() << " miliseconds" << std::endl;
            break;
        case 6:
            start = std::chrono::high_resolution_clock::now();
            s->mergeSort();
            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            std::cout << "Time taken by function: " << elapsed.count() << " miliseconds" << std::endl;
            break;
        case 7:
            start = std::chrono::high_resolution_clock::now();
            s->bucketSort();
            end = std::chrono::high_resolution_clock::now();
            elapsed = end - start;
            std::cout << "Time taken by function: " << elapsed.count() << " miliseconds" << std::endl;
            break;
        case 8:
            s->shuffle();
            break;
        case 9:
            delete s;
            return 0;
        default:
            std::cout << "Wrong choice\n";
            break;
        }
    }
}