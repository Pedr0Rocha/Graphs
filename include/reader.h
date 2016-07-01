#ifndef READER_H
#define READER_H

#include <stdio.h>
#include "graph.h"

void readVertexAndEdgeCount(char *path, int *numVertices, int *numEdges);
void createGraphFromInput(char *path, Vertex graph[], int numVertices, int numEdges, int directed);

#endif