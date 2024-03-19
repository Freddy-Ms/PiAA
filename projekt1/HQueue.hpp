#include <iostream>
using namespace std;

struct Packet{
    int data;
    int priority; // Najwyższy priorytet 1, najmniejszy 100
};
class PriorityQueue{
    private:
        Packet* tab;
        int size;
        int actualsize;
    public:
    PriorityQueue(int size);
    ~PriorityQueue();                       
    void add(Packet packet);
    void generate_mssg(int n);
    void generate_mssg_sorted(int n);
    bool isempty();
    void show();                        
    void make_heap();
    void heap_sort();
    void resize();
};                                           