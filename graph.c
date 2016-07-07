#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "include/graph.h"

Vertex* createVertex(char name) {
	Vertex *v = malloc(sizeof(Vertex));
	(*v) = (Vertex) {
		.name = name,
		.father = NULL,
		.color = WHITE,
		.dt = -1,
		.ft = -1,
		.distance = INT_MAX,
		.adjList = NULL,
		.adjListSize = 0
	};
	return v;
}

void initVertex(char name, Vertex *v) {
	*v = (Vertex) {
		.name = name,
		.father = NULL,
		.color = WHITE,
		.dt = -1,
		.ft = -1,
		.distance = INT_MAX,
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

void printAdjList(Vertex *graph, int numVertex) {
	for (int i = 0; i < numVertex; i++) {
		printf("%c Adj Size: %d\n", graph[i].name, graph[i].adjListSize);
		AdjList *adj = graph[i].adjList;
		while (adj != NULL) {
			printf("Adj -> %c\n", adj->vertex->name);
			adj = adj->prev;
		}
	}
}