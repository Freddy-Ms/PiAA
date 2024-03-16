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
    public:
    PriorityQueue(int size);
    ~PriorityQueue();                        // Dwie formy, jedna po kolei dodajemy pakiet i "naprawiamy kopiec" albo od razu
    void add(Packet packet);
    void generate_mssg(int n);
    bool isempty();
    void show();                        //Pokazuje tylko priority, to jest dla nas najwazniejsze
    void make_heap();
    void heap_sort();
    void resize();
};                                           // generujemy n pakietów i tworzymy kopiec a następnie go całego ściągamy