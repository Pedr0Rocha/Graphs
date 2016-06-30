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
		.adjListSize = 0
	};
	return v;
}

void initVertex(char name, Vertex *v) {
	(*v) = (Vertex) {
		.name = name,
		.father = NULL,
		.color = WHITE,
		.dt = -1,
		.ft = -1,
		.adjListSize = 0
	};
}

void connectVertex(Vertex *v, Vertex *u) {
	addToAdjList(v, &u->adjList);
	addToAdjList(u, &v->adjList);
	v->adjListSize++;
	u->adjListSize++;
}

void addToAdjList(Vertex *v, AdjList **adjList) {
	if (*adjList == NULL){
		*adjList = malloc(sizeof(AdjList));
		(**adjList).vertex = v;
		(**adjList).prev = NULL;
	} else {
		AdjList *new;
		new = malloc(sizeof(AdjList));
		new->vertex = v;
		new->prev = *adjList;
		*adjList = new;
	}
}

int adjListContains(Vertex *v, AdjList *adjList) {
	AdjList *current = adjList;
	while (current != NULL){
		if (current->vertex->name == v->name) return 1;
		current = current->prev;
	}
	return 0;
}