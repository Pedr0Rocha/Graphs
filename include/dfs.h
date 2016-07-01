#ifndef DFS_H
#define DFS_H

#include <stdio.h>

void dfs(Vertex graph[], int numVertices);
void dfsVisit(Vertex *vertex);
void printTopologicalOrder(int numVertices);
void printDfsResults(Vertex graph[], int numVertices);

#endif