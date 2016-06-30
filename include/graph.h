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
		ft; // final time
	AdjList *adjList;
	int adjListSize;
};

struct AdjList {
	Vertex *vertex;
	AdjList *prev;
};

void initVertex(char name, Vertex *v);
void connectVertex(Vertex *v, Vertex *u);
Vertex* createVertex(char name);
void addToAdjList(Vertex *v, AdjList **adjList);
int adjListContains(Vertex *v, AdjList *adjList);

#endif