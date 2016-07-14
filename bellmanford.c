#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/bellmanford.h"

int bellmanFord(Vertex graph[], Edge edges[], int origin, int numVertices, int numEdges) {
	graph[origin].distance = 0;	

	for (int i = 0; i < numVertices - 1; i++)
		for (int j = numEdges - 1; j > 0; j--)
			relax(&graph[edges[j].u], &graph[edges[j].v], edges[j].weight);
		
	for (int j = 0; j < numEdges; j++)
		if (graph[edges[j].v].distance > graph[edges[j].u].distance + edges[j].weight) {
			printf("Negative Cycle Found!\n");
			return 0;
		}
	return 1;
}


void relax(Vertex *u, Vertex *v, int weight) {
	if (v->distance > (u->distance + weight)) {
		v->distance = u->distance + weight;
		v->father = u;
	}
}

void printBellmanFordResults(Vertex graph[], int numVertices, int goalVertex) {
	Vertex *current = &graph[goalVertex];
	int totalDistance = 0;
	while (current) {
		printf("Vertex %c - Distance = %d - ", current->name, current->distance);
		totalDistance += current->distance;
		if (current->father != NULL)
			printf("Father %c \n", current->father->name);
		else
			printf("Father NULL\n");
		current = current->father;
	}
	printf("Total Distance = %d\n", totalDistance);
}

