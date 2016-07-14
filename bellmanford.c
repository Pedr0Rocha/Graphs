#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/bellmanford.h"

int bellmanFord(Vertex graph[], Edge edges[], int origin, int numVertices, int numEdges) {
	graph[origin].distance = 0;
	for (int i = 0; i < numVertices - 1; i++)
		for (int j = numEdges - 1; j >= 0; j--) 
			relax(&graph[edges[j].u], &graph[edges[j].v], edges[j].weight);

	for (int j = 0; j < numEdges - 1; j++)
		if (graph[edges[j].v].distance > graph[edges[j].u].distance + edges[j].weight)
			return 0;
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
	if (current->distance > 99999) { 
		printf("There is no path between the goal and initial vertex\n");
		exit(0);
	}

	int totalWeight = 0;
	while (current) {
		printf("Vertex %c - Weight = %d - ", current->name, current->distance);
		totalWeight += current->distance;
		if (current->father != NULL)
			printf("Father %c \n", current->father->name);
		else
			printf("No Father\n");
		current = current->father;
	}
	printf("Total Weight = %d\n", totalWeight);
}

