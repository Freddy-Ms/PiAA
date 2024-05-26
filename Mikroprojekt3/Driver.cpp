#include"Graph.cpp"
#include <chrono>
#pragma once


void driver(){
    bool run = true;
    cout << "How many Vertices do you want to have in your graph?" << endl;
    int inputVertex;
    cin >> inputVertex;
    Graph *g = new Graph(inputVertex);
    while(run){
        cout << "Menu:" << endl;
        cout << "0. Change number of Vertices" << endl;
        cout << "1. Add edge" << endl;
        cout << "2. Remove edge" << endl;
        cout << "3. Generate random graph" << endl;
        cout << "4. Dijkstra algorithm with Adjacency List" << endl;
        cout << "5. Dijkstra algorithm with Adjacency Matrix" << endl;
        cout << "6. How many Vertex?" << endl;
        cout << "7. How many Edges?" << endl;
        cout << "8. Print Adjacency Matrix" << endl;
        cout << "9. Print Adjacency List" << endl;
        cout << "10. Exit" << endl;
        cout << "Choose option: ";
        int choice;
        cin >> choice;
        int V1,V2,weight;
        int StartVertex;
        std::chrono::high_resolution_clock::time_point begin, end;
        switch(choice){
            case 0:
                cout << "How many Vertices do you want to have in your graph?" << endl;
                cin >> inputVertex;
                delete g;
                g = new Graph(inputVertex);
                break;
            case 1:
                cout << "Enter the first vertex, second vertex and the weight: ";
                cin >> V1 >> V2 >> weight;
                g->addEdge(V1, V2, weight);
                break;
            case 2:
                cout << "Enter the both vertex: ";
                cin >> V1 >> V2;
                g->removeEdge(V1, V2);
                break;
            case 3:
                cout << "Enter the density of the graph: ";
                int density;
                cin >> density;
                g->generateGraph(density);
                break;
            case 4:
                cout << "Enter the start vertex: ";
                cin >> StartVertex;
                begin = std::chrono::high_resolution_clock::now();
                g->DijkstraWithList(StartVertex);
                end = std::chrono::high_resolution_clock::now();
                cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "microseconds" << std::endl;
                break;
            case 5:
                cout << "Enter the start vertex: ";
                cin >> StartVertex;
                begin = std::chrono::high_resolution_clock::now();
                g->DijkstraWithMatrix(StartVertex);
                end = std::chrono::high_resolution_clock::now();
                cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "microseconds" << std::endl;
                break;
            case 6:
                cout << "Number of Vertices: " << g->getVertex() << endl;
                break;
            case 7:
                cout << "Number of Edges: " << g->getEdges() << endl;
                break;
            case 8:
                g->printMatrix();
                break;
            case 9:
                g->printList();
                break;
            case 10:
                delete g;
                run = false;
                break;
            default:
                cout << "Wrong option!" << endl;
                break;
        }
    }
}