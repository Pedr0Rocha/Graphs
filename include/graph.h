#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

#define WHITE 0
#define GRAY  1
#define BLACK 2

typedef struct Vertex Vertex;
typedef struct AdjList AdjList;

struct Vertex {
	char name;
	Vertex *father;
	int color, 
		dt, // discovery time 
		ft, // final time
		distance;
	AdjList *adjList;
	int adjListSize;
};

struct AdjList {
	Vertex *vertex;
	AdjList *prev;
};

void initVertex(char name, Vertex *v);
void connectVertices(Vertex *v, Vertex *u);
void addToAdjList(Vertex *v, Vertex *u);
void insertAdjList(Vertex *v, AdjList **adjList);
Vertex* createVertex(char name);
int adjListContains(Vertex *v, AdjList *adjList);
void printAdjList(Vertex *graph, int numVertex);

#endif