#ifndef READER_H
#define READER_H

#include <stdio.h>
#include "graph.h"

void readVertexAndEdgeCount(char *path, int *numVertices, int *numEdges);
void createGraphFromInput(char *path, Vertex graph[], Edge edges[], int numVertices, int numEdges);

#endif