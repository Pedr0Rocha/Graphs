#ifndef HRT_H
#define HRT_H

#include <stdio.h>

void hrt(Vertex graph[], Edge edges[], Vertex *initialVertex, int numVertices, int numEdges);
void printHrtResults(Vertex graph[], int numVertices);

#endif