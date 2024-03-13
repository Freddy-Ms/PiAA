#include <iostream>
using namespace std;

struct Packet{
    int data;
    int priority; // Najwyższy priorytet 1, najmniejszy 100
};
class PriorityQueue{
    private:
        Packet * tab;
        int size;
        int actualsize;
        void repairUp(int i);
        void repairDown(int i);
    public:
    PriorityQueue(int size);
    ~PriorityQueue();                        // Dwie formy, jedna po kolei dodajemy pakiet i "naprawiamy kopiec" albo od razu
    void add(Packet packet);
    void get_heap();
    bool isempty();
    void show();                        //Pokazuje tylko priority, to jest dla nas najwazniejsze
    void make_heap();
    void heap_sort();
};                                           // generujemy n pakietów i tworzymy kopiec a następnie go całego ściągamy