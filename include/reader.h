#ifndef READER_H
#define READER_H

#include <stdio.h>
#include "graph.h"

int readVertexCount(char *path);
void createGraphFromInput(char *path, Vertex graph[]);

#endif