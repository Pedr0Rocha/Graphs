#ifndef DFS_H
#define DFS_H

#include <stdio.h>

void dfs(Vertex graph[], int numVertex);
void dfsVisit(Vertex *vertex);
void printTopologicalOrder(int numVertex);
void printDfsResults(Vertex graph[], int numVertex);

#endif