#ifndef DFS_H
#define DFS_H

#include <stdio.h>

void dfs(Vertex graph[], Vertex *initialVertex, int numVertices);
void dfsVisit(Vertex *vertex);
void dfsScc(Vertex graph[], Vertex *initialVertex, int numVertices);
void dfsVisitScc(Vertex *vertex);
void printTopologicalOrder(int numVertices);
void printDfsResults(Vertex graph[], int numVertices);

#endif