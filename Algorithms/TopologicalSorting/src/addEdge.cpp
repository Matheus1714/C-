#include "../headers/graph.h"

void Graph::addEdge(int nodeV, int nodeW){
    adjList[nodeV].push_back(nodeW);
}