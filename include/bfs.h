#ifndef BFS_H
#define BFS_H

#include <stdio.h>

void bfs(Vertex graph[], Vertex *initialVertex, int numVertices);
Vertex* getNotVisited(Vertex graph[], int numVertices);
int hasUnvisited(Vertex graph[], int numVertices);
void printBfsResults(Vertex graph[], int numVertices);

#endif