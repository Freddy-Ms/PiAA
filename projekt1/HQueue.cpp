#include "HQueue.hpp"
#include <iostream>
#include <random>
using namespace std;

PriorityQueue::PriorityQueue(int size) : size(size) , actualsize(0){
    tab = new Packet[size];
};
PriorityQueue::~PriorityQueue(){ delete[] tab;};
void PriorityQueue::add(Packet packet)
{
    tab[actualsize] = packet;
    actualsize++;
};
void PriorityQueue::generate_mssg(int n){
    if(size >= n)
    {
    for(int i = 0; i < n; i++){
        tab[actualsize].data = rand() % 100000;
        tab[actualsize].priority = rand() % 100 + 1;
        actualsize++;
    };
    }else{
        resize();
        generate_mssg(n);
    };
};
void PriorityQueue::resize(){
    int newsize = 2 * size;
    Packet *nTab = new Packet[newsize];
    delete[] tab;
    tab = nTab;
    size = newsize;    
}
bool PriorityQueue::isempty(){
    return actualsize == 0;
};
void PriorityQueue::show(){
    for(int i = 0; i < size; i++){
        cout << tab[i].priority << " ";
    }
};
void PriorityQueue::make_heap(){

    for(int i = 1;i<actualsize;i++)
    {
        int child = i;
        int parent = (child - 1) / 2;
        int value = tab[child].priority;
        while((child > 0) && (tab[parent].priority < value))
        {
            tab[child].priority = tab[parent].priority;
            child = parent; parent = (child - 1) / 2;
        }
        tab[child].priority = value;
    }
};    
void PriorityQueue::heap_sort(){

};