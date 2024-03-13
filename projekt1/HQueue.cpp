#include "HQueue.hpp"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue(int size) : size(size) , actualsize(0){
    tab = new Packet[size];
};
PriorityQueue::~PriorityQueue(){ delete[] tab;};
void PriorityQueue::repairUp(int i){

};
void PriorityQueue::repairDown(int i){

};
void PriorityQueue::add(Packet packet)
{

};
void PriorityQueue::get_heap(){

};
bool PriorityQueue::isempty(){
    return actualsize == 0;
};
void PriorityQueue::show(){
    for(int i = 0; i < size; i++){
        cout << tab[i].priority << " ";
    }
};
void PriorityQueue::make_heap(){

};
void PriorityQueue::heap_sort(){

};