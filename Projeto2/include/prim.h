#ifndef PRIM_H
#define PRIM_H

#include <stdio.h>

void prim(Vertex graph[], Edge edges[], Vertex *initialVertex, int numVertices, int numEdges);
void printPrimResults(Vertex graph[], int numVertices);

#endif