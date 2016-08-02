#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "include/graph.h"

Vertex* createVertex(int name) {
	Vertex *v = malloc(sizeof(Vertex));
	(*v) = (Vertex) {
		.name = name,
		.father = NULL,
		.visited = 0,
		.key = INT_MAX-9999,
		.adjList = NULL,
		.adjListSize = 0
	};
	return v;
}

void initVertex(int name, Vertex *v) {
	*v = (Vertex) {
		.name = name,
		.father = NULL,
		.visited = 0,
		.key = INT_MAX-9999,
		.adjList = NULL,
		.adjListSize = 0
	};
}

void connectVertices(Vertex *v, Vertex *u, int weight) {
	insertAdjList(v, &u->adjList, weight);
	insertAdjList(u, &v->adjList, weight);
	v->adjListSize++;
	u->adjListSize++;
}

void addToAdjList(Vertex *v, Vertex *u, int weight) {
	insertAdjList(u, &v->adjList, weight);
	v->adjListSize++;
}

void addToEdgeArray(Edge edges[], int addAtIndex, int vIndex, int uIndex, int weight) {
	edges[addAtIndex].v = vIndex;
	edges[addAtIndex].u = uIndex;
	edges[addAtIndex].weight = weight;
}

void insertAdjList(Vertex *v, AdjList **adjList, int weight) {
	if (*adjList == NULL) {
		*adjList = malloc(sizeof(AdjList));
		(**adjList).vertex = v;
		(**adjList).weight = weight;
		(**adjList).prev = NULL;
	} else {
		AdjList *new = malloc(sizeof(AdjList));
		new->vertex = v;
		new->weight = weight;
		new->prev = *adjList;
		*adjList = new;
	}
}

int adjListContains(Vertex *v, AdjList *adjList) {
	AdjList *current = adjList;
	while (current != NULL) {
		if (current->vertex->name == v->name) return 1;
		current = current->prev;
	}
	return 0;
}

int findIndexByName(Vertex graph[], int name, int numVertices) {
	for (int i = 0; i < numVertices; i++)
		if (graph[i].name == name) return i;
	return -1;
}

int getDistance(Edge edges[], int u, int v, int numEdges) {
	for (int i = 0; i < numEdges; i++) {
		if (edges[i].u == u && edges[i].v == v) return edges[i].weight; 
	}
	return 0;
}

void printAdjList(Vertex *graph, int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		printf("%d Adj Size: %d\n", graph[i].name, graph[i].adjListSize);
		AdjList *adj = graph[i].adjList;
		while (adj != NULL) {
			printf("Adj -> %d\n", adj->vertex->name);
			adj = adj->prev;
		}
	}
}