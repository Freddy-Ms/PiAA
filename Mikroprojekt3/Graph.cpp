#include "Graph.hpp"
#pragma once
#include <vector>
#include <queue>
#include <limits.h>
void Graph::InitializationMatrix() {
    AdjMatrix = new int*[this->Vertex];
    for (int i = 0; i < this->Vertex; i++) {
        AdjMatrix[i] = new int[Vertex];
    }
    for (int i = 0; i < this->Vertex; i++) {
        for (int j = 0; j < this->Vertex; j++) {
            AdjMatrix[i][j] = 0;
        }
    }
}
void Graph::DestroyMatrix() {
    for (int i = 0; i < this->Vertex; i++) {
        delete[] AdjMatrix[i];
    }
    delete[] AdjMatrix;
}
Graph::Graph(int Vertex) {
    this->Vertex = Vertex;
    this->Edges = 0;
    InitializationMatrix();
    AdjList = new list<vPair>[Vertex];
}
Graph::~Graph() {
    DestroyMatrix();
    delete[] AdjList;
}
void Graph::addEdge(int V1, int V2, int weight) {
    AdjMatrix[V1][V2] = weight;
    AdjMatrix[V2][V1] = weight;
    AdjList[V1].push_back(make_pair(V2, weight));
    AdjList[V2].push_back(make_pair(V1, weight));
    this->Edges++;
}
void Graph::removeEdge(int V1, int V2) {
    AdjMatrix[V1][V2] = 0;
    AdjMatrix[V2][V1] = 0;
    for (auto i = AdjList[V1].begin(); i != AdjList[V1].end(); i++) {
        if (i->first == V2) {
            AdjList[V1].erase(i);
            break;
        }
    }
    for (auto i = AdjList[V2].begin(); i != AdjList[V2].end(); i++) {
        if (i->first == V1) {
            AdjList[V2].erase(i);
            break;
        }
    }
    this->Edges--;
}
void Graph::DijkstraWithList(int StartVertex){
    priority_queue<vPair, vector<vPair>, greater<vPair>> pq;
    int *dist = new int[this->Vertex];
    for(int i = 0; i<this->Vertex; i++)
        dist[i] = INT_MAX;
    pq.push(make_pair(0, StartVertex));
    dist[StartVertex] = 0;
    while(!pq.empty()){
        int Vertex = pq.top().second;
        pq.pop();
        for(auto i : AdjList[Vertex]){
            int DestinationVertex = i.first;
            int weight = i.second;
            if(dist[DestinationVertex] > dist[Vertex] + weight){
                dist[DestinationVertex] = dist[Vertex] + weight;
                pq.push(make_pair(dist[DestinationVertex], DestinationVertex));
            }
        }

    }
    printSolution(dist);
    delete[] dist;
}
void Graph::DijkstraWithMatrix(int StartVertex){
    priority_queue<vPair, vector<vPair>, greater<vPair>> pq;
    int *dist = new int[this->Vertex];
    for(int i = 0; i<this->Vertex; i++)
        dist[i] = INT_MAX;
    pq.push(make_pair(0, StartVertex));
    dist[StartVertex] = 0;
    while(!pq.empty()){
        int Vertex = pq.top().second;
        pq.pop();
        for(int i = 0; i<this->Vertex; i++){
            if(AdjMatrix[Vertex][i] != 0){
                int DestinationVertex = i;
                int weight = AdjMatrix[Vertex][i];
                if(dist[DestinationVertex] > dist[Vertex] + weight){
                    dist[DestinationVertex] = dist[Vertex] + weight;
                    pq.push(make_pair(dist[DestinationVertex], DestinationVertex));
                }
            }
        }
    }
    printSolution(dist);
    delete[] dist;
}
void Graph::printSolution(int *dist){
    cout << "Vertex \t Distance from Source Vertex" << endl;
    for(int i = 0; i<this->Vertex; i++){
        cout << i << " \t\t " << dist[i] << endl;
    }
}
int Graph::getVertex(){
    return this->Vertex;
}
int Graph::getEdges(){
    return this->Edges;
}
void Graph::printList(){
    for(int i = 0; i<this->Vertex; i++){
        cout << "Vertex " << i << " is connected with: ";
        for(auto j : AdjList[i]){
            cout << j.first << " with weight " << j.second << ", ";
        }
        cout << endl;
    }
}
void Graph::printMatrix(){
    for(int i = 0; i<this->Vertex; i++){
        for(int j = 0; j<this->Vertex; j++){
            cout << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}