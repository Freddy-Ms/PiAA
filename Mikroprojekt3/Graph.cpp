#include "Graph.hpp"
#pragma once
#include <random>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <limits.h>
void Graph::FullfilZerosMatrix(){
    for(int i = 0; i<this->Vertex; i++){
        for(int j = 0; j<this->Vertex; j++){
            AdjMatrix[i][j] = 0;
        }
    }
}
void Graph::ClearAdjList(){
    for(int i = 0; i<this->Vertex; i++){
        AdjList[i].clear();
    }
}
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
    bool *visited = new bool[this->Vertex];
    for(int i = 0; i<this->Vertex; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    pq.push(make_pair(0, StartVertex));
    dist[StartVertex] = 0;
    while(!pq.empty()){
        int Vertex = pq.top().second;
        pq.pop();
        if(visited[Vertex] == true)
            continue;  
        
        for(auto i : AdjList[Vertex]){
            int DestinationVertex = i.first;
            if(visited[DestinationVertex] == true)
                continue;
            int weight = i.second;
            if(dist[DestinationVertex] > dist[Vertex] + weight){
                dist[DestinationVertex] = dist[Vertex] + weight;
                pq.push(make_pair(dist[DestinationVertex], DestinationVertex));
            }
        }
        visited[Vertex] = true;
    }
   // printSolution(dist);
    delete[] dist;
    delete[] visited;
}
void Graph::DijkstraWithMatrix(int StartVertex){
    priority_queue<vPair, vector<vPair>, greater<vPair>> pq;
    int *dist = new int[this->Vertex];
    bool *visited = new bool[this->Vertex];
    for(int i = 0; i<this->Vertex; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    pq.push(make_pair(0, StartVertex));
    dist[StartVertex] = 0;
    while(!pq.empty()){
        int Vertex = pq.top().second;
        pq.pop();
        if(visited[Vertex] == true)
            continue;
        for(int i = 0; i<this->Vertex; i++){
            if(AdjMatrix[Vertex][i] != 0){
                int DestinationVertex = i;
                if(visited[DestinationVertex] == true)
                    continue;
                int weight = AdjMatrix[Vertex][i];
                if(dist[DestinationVertex] > dist[Vertex] + weight){
                    dist[DestinationVertex] = dist[Vertex] + weight;
                    pq.push(make_pair(dist[DestinationVertex], DestinationVertex));
                }
            }
        }
        visited[Vertex] = true;
    }
   // printSolution(dist);
    delete[] dist;
    delete[] visited;
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
void Graph::generateGraph(int density){
    vector<pair<int, int>> allEdges;
    set<pair<int, int>> usedEdges;
    random_device rd;
    default_random_engine rng(rd());
    FullfilZerosMatrix();
    ClearAdjList();
    this->Edges = 0;
    // Generate all possible edges for an undirected graph
    for (int u = 0; u < this->Vertex; ++u) {
        for (int v = u + 1; v < this->Vertex; ++v) {
            allEdges.push_back(make_pair(u, v));
        }
    }

    // Shuffle the edges to randomly select the required number of edges
    shuffle(allEdges.begin(), allEdges.end(), rng);

    // Calculate the exact number of edges based on the density
    int totalPossibleEdges = allEdges.size();
    int edgesToAdd = (density * totalPossibleEdges) / 100;

    // Ensure each vertex has at least one edge by creating a minimal spanning tree (or similar structure)
    for (int i = 0; i < this->Vertex - 1; ++i) {
        int u = i;
        int v = i + 1;
        int weight = rand() % 100 + 1; // Random weight between 1 and 100
        addEdge(u, v, weight);
        usedEdges.insert(make_pair(min(u, v), max(u, v))); // Track the added edge
    }

    edgesToAdd -= (this->Vertex - 1);

    // Now add the remaining edges
    int edgeIndex = 0;
    while (edgesToAdd > 0 && edgeIndex < totalPossibleEdges) {
        int u = allEdges[edgeIndex].first;
        int v = allEdges[edgeIndex].second;

        // Ensure we do not add duplicate edges
        if (usedEdges.find(make_pair(min(u, v), max(u, v))) != usedEdges.end()) {
            edgeIndex++;
            continue;
        }

        addEdge(u, v, rand() % 100 + 1);
        usedEdges.insert(make_pair(min(u, v), max(u, v))); // Track the added edge
        edgesToAdd--;
        edgeIndex++;
    }
}