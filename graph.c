#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"

Vertex* createVertex(char name) {
	Vertex *v = malloc(sizeof(Vertex));
	(*v) = (Vertex) {
		.name = name,
		.father = NULL,
		.color = WHITE,
		.dt = -1,
		.ft = -1,
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
		.adjList = NULL,
		.adjListSize = 0
	};
}

void connectTwoVertex(Vertex *v, Vertex *u) {
	insertAdjList(v, &u->adjList);
	insertAdjList(u, &v->adjList);
	v->adjListSize++;
	u->adjListSize++;
}

void addToAdjList(Vertex *v, Vertex *u) {
	insertAdjList(u, &v->adjList);
	v->adjListSize++;
}

void insertAdjList(Vertex *v, AdjList **adjList) {
	if (*adjList == NULL) {
		*adjList = malloc(sizeof(AdjList));
		(**adjList).vertex = v;
		(**adjList).prev = NULL;
	} else {
		AdjList *new = malloc(sizeof(AdjList));
		new->vertex = v;
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