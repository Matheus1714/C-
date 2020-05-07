#include "../headers/graph.h"

void Graph::topologicalSortUtil(int NumberOfVertices, bool *nodeVisited, stack<int> &Stack){
    nodeVisited[NumberOfVertices] = true;
    list<int>::iterator i;
    for( i = adjList[NumberOfVertices].begin(); i != adjList[NumberOfVertices].end(); i++ ){
        if(!nodeVisited[*i]){
            topologicalSortUtil(*i, nodeVisited, Stack);
        }
    }
    Stack.push(NumberOfVertices);
}