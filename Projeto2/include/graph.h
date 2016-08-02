#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>

#define WHITE 0
#define GRAY  1
#define BLACK 2

typedef struct Vertex Vertex;
typedef struct AdjList AdjList;

struct Vertex {
	int name;
	Vertex *father;
	int visited, 
		key;
	AdjList *adjList;
	int adjListSize;
};

struct AdjList {
	Vertex *vertex;
	AdjList *prev;
	int weight;
};

typedef struct {
	int u;
	int v;
	int weight;
} Edge;

void initVertex(int name, Vertex *v);
void connectVertices(Vertex *v, Vertex *u, int weight);
void addToAdjList(Vertex *v, Vertex *u, int weight);
void addToEdgeArray(Edge edges[], int addAtIndex, int vIndex, int uIndex, int weight);
void insertAdjList(Vertex *v, AdjList **adjList, int weight);
Vertex* createVertex(int name);
int adjListContains(Vertex *v, AdjList *adjList);
int getDistance(Edge edges[], int u, int v, int numEdges);
void printAdjList(Vertex *graph, int numVertices);

#endif