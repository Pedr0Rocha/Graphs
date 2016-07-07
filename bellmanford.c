#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/bellmanford.h"

int bellmanFord(Vertex graph[], Edge edges[], Vertex *origin, Vertex *goal, int numVertices, int numEdges) {
	origin->distance = 0;	

	for (int i = 0; i < numEdges; i++)
		printf("Edge %d is weight %d\n", i, edges[i].weight);

	for (int i = 1; i < numVertices - 1; i++) {
		for (int j = 0; j < numEdges; j++) {
			relax(&graph[edges[j].u], &graph[edges[j].v], edges[j].weight);
		}
	}
	for (int j = 0; j < numEdges; j++)
		if (&graph[edges[j].u].distance > &graph[edges[j].v].distance + edges[j].weight)
			return 0;
	return 1;
}


void relax(Vertex *u, Vertex *v, int weight) {
	printf("Relaxing %c and %c\n", u->name, v->name);
	if (v->distance > (u->distance + weight)) {
		printf("Updated weight %d to %d\n", v->distance, (u->distance + weight));
		v->distance = u->distance + weight;
		v->father = u;
	}
}

void printBellmanFordResults(Vertex graph[], int goalVertex, int numVertices) {
	Vertex *vertex = &graph[goalVertex];
	while (vertex->father != NULL) {
		printf("Vertex %c - ", vertex->name);
		printf("Father %c \n", vertex->father->name);
		vertex = vertex->father;
	}
}

