#include "../headers/graph.h"

Graph::Graph(int NumberOfVertices){
    this->NumberOfVertices = NumberOfVertices;
    adjList = new list<int>[NumberOfVertices];
}