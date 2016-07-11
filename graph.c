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

void removeFromAdjList(char vertexName, AdjList **adjList, char adjListOwner) {
	printf("Vertex %c removed from %c adjList\n", vertexName, adjListOwner);
}

int adjListContains(Vertex *v, AdjList *adjList) {
	AdjList *current = adjList;
	while (current != NULL) {
		if (current->vertex->name == v->name) return 1;
		current = current->prev;
	}
	return 0;
}

void transposeGraph(Vertex graph[], int numVertices) {
	printAdjList(graph, numVertices);
	for (int i = 0; i < numVertices; i++) {
		AdjList *adj = graph[i].adjList;
		while (adj != NULL) {
			Vertex *v = adj->vertex;
			// add graph[i] to v->adjList and remove v from graph[i].adjList
			removeFromAdjList(v->name, &graph[i].adjList, graph[i].name);
			addToAdjList(&graph[i], v, 0);
			adj = adj->prev;
		}
	}	
}

void sortByFinalTime(Vertex graph[], int numVertices) {
	quickSort(graph, 0, numVertices-1);
}

void quickSort(Vertex graph[], int left, int right) {
	int pivot = left;
	printf("pivot = %d\n", pivot);
}

void printAdjList(Vertex *graph, int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		printf("%c Adj Size: %d\n", graph[i].name, graph[i].adjListSize);
		AdjList *adj = graph[i].adjList;
		while (adj != NULL) {
			printf("Adj -> %c\n", adj->vertex->name);
			adj = adj->prev;
		}
	}
}