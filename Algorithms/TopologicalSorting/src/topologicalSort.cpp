#include "../headers/graph.h"

void Graph::topologicalSort(){
    stack<int> Stack;

    bool *nodeVisited = new bool[NumberOfVertices];
    for(int i = 0; i<NumberOfVertices; i++){
        nodeVisited[i] = false;
    }
    for(int i=0; i<NumberOfVertices; i++){
        if(!nodeVisited[i]){
            topologicalSortUtil(i, nodeVisited, Stack);
        }
    }
    while(!Stack.empty()){
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
}