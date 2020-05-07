#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Graph{
    int NumberOfVertices;
    list<int> *adjList;

    void topologicalSortUtil(int NumberOfVertices, bool *nodeVisited, stack<int> &Stack);

    public:
        Graph(int NUmberOfVertices);

        void addEdge(int nodeV, int nodeW);

        void topologicalSort();
};

#endif