#include <iostream>
#include "HQueue.cpp"
using namespace std;


const int n = 15;
struct packet {
    int priority;
    int message;
};
class pQueue{
public:
    packet tab[n];
    void generate_message(){
        for(int i = 0; i<n;i++)
        {
            tab[i].message = rand() % 10000;
            tab[i].priority = rand() % 10 + 1;
        }
    };
    void show(){
        for(int i = 0; i<n;i++)
        {
            cout << tab[i].priority << " ";
        }
    };
    void make_heap(){

        for(int i = 1;i<n;i++)
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
    void sort_heap(){
        
    };
};
int main()
{
    pQueue Q;
    Q.generate_message();
    Q.show(); cout << endl;
    Q.make_heap();
    Q.show();
}