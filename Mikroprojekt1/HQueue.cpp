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
        tab[actualsize].data = rand() % 10;
        tab[actualsize].priority = rand() % 10000000 + 1;
        actualsize++;
    };
    }else{
        resize();
        generate_mssg(n);
    };
};
void PriorityQueue::generate_mssg_sorted(int n){
    int j = n;
    for(int i = 0; i < n; i++)
    {
        tab[actualsize].data = rand() % 10;
        tab[actualsize].priority = j;
        actualsize++;
        j--;
    }
}
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
    int child,parent;
    for(int i = 1;i<actualsize;i++)
    {
        child = i;
        parent = (child - 1) / 2;
        while((child > 0) && (tab[parent].priority < tab[child].priority))
        {
            swap(tab[child],tab[parent]);
            child = parent; parent = (child - 1) / 2;
        }
    }
};    
void PriorityQueue::heap_sort(){
    int parent, lchild, rchild, to_swap;
    for(int i = actualsize-1;i > 0;i--){
            swap(tab[0],tab[i]);
            parent = 0;
            lchild = 1;
            rchild = 2;
            to_swap = parent;
            while(1){
                if(lchild < i && tab[lchild].priority > tab[to_swap].priority){
                    to_swap = lchild;
                }
                if(rchild < i && tab[rchild].priority > tab[to_swap].priority){
                    to_swap = rchild;
                }
                if(parent != to_swap){
                    swap(tab[parent],tab[to_swap]);
                    parent = to_swap;    
                    lchild = parent * 2 + 1;
                    rchild = parent * 2 + 2;
                } else {break;}   
            }
    }
}