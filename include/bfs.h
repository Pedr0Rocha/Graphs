#ifndef BFS_H
#define BFS_H

#include <stdio.h>

void bfs(Vertex graph[], Vertex *initialVertex, int numVertex);
Vertex* getNotVisited(Vertex graph[], int numVertex);
int hasUnvisited(Vertex graph[], int numVertex);
void printBfsResults(Vertex graph[], int numVertex);

#endif