#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/hrt.h"

Vertex* nearestNeightbor(AdjList *adjList) {
	Vertex *v;
	int minWeight = 9999;
	while (adjList != NULL) {
		if (adjList->weight < minWeight) {
			minWeight = adjList->weight;
			v = adjList->vertex;
		}
		adjList = adjList->prev;
	}
	return v;
}

int notOnList(Vertex **mst, int currentIndex, Vertex *v) {
	for (int i = 0; i < currentIndex; i++) 
		if (mst[i]->name == v->name) return 0;
	return 1;
}

void hrt(Vertex graph[], Edge edges[], Vertex *initialVertex, int numVertices, int numEdges) {
	Vertex **mst = malloc(numVertices * sizeof(Vertex));
	int indexVertices = 0;
	mst[indexVertices++] = initialVertex;

	Vertex *v = initialVertex;
	printf("%d ", initialVertex->name);
	while (indexVertices < numVertices) {
		Vertex *nearest = nearestNeightbor(v->adjList);
		if (notOnList(mst, indexVertices, nearest)) {
			mst[indexVertices++] = nearest;
			printf("%d ", nearest->name);
		}
		v = nearest;
	}
	printHrtResults(graph, numVertices);
}

void printHrtResults(Vertex graph[], int numVertices) {
	int totalWeight = 0;
	for (int i = 0; i < numVertices; i++) {
		if (i == 0) printf("\n");
		if (graph[i].father)
			printf("Vertex %d - Father %d - Key %d\n", graph[i].name, graph[i].father->name, graph[i].key);
		else 	
			printf("Vertex %d - Father %p - Key %d\n", graph[i].name, graph[i].father, graph[i].key);
		totalWeight += graph[i].key;
	}
	printf("Total Weight: %d\n", totalWeight);
}