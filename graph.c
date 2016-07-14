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
		.distance = INT_MAX-9999,
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
		.distance = INT_MAX-9999,
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

int findIndexByName(Vertex graph[], char name, int numVertices) {
	for (int i = 0; i < numVertices; i++)
		if (graph[i].name == name) return i;
	return -1;
}

int compare (const void * a, const void * b) {
  Vertex *u = (Vertex *)a;
  Vertex *v = (Vertex *)b;
  if (u->ft > v->ft) return -1;
  else if (u-> ft < v->ft) return 1;
  else return 0;
}

void transposeGraph(Vertex graph[], Vertex graphT[], int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		initVertex(graph[i].name, &graphT[i]);
		graphT[i].ft = graph[i].ft;
	}
	qsort(graphT, numVertices, sizeof(Vertex), compare);
	for (int i = 0; i < numVertices; i++) {
		AdjList *adj = graph[i].adjList;
		while (adj != NULL) {
			Vertex *v = adj->vertex;
			int graphIndex = findIndexByName(graphT, v->name, numVertices);
			int graphIndexToAdd = findIndexByName(graphT, graph[i].name, numVertices);
			addToAdjList(&graphT[graphIndex], &graphT[graphIndexToAdd], 1);
			adj = adj->prev;
		}
	}
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