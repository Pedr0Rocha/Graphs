#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/dfs.h"

int time = 0;
int topologicalIndex;
char *topologicalOrder;

void dfs(Vertex graph[], int numVertices) {
	topologicalOrder = malloc(sizeof(char) * numVertices);
	topologicalIndex = numVertices - 1;

	for (int i = 0; i < numVertices; i++)
		if (graph[i].color == WHITE)
			dfsVisit(&graph[i]);
	printTopologicalOrder(numVertices);
}

void dfsVisit(Vertex *vertex) {
	time++;
	vertex->color = GRAY;
	vertex->dt = time;
	AdjList *adj = vertex->adjList;
	while (adj != NULL) {
		Vertex *v = adj->vertex;
		if (v->color == WHITE) {
			v->father = vertex;
			dfsVisit(v);
		}
		adj = adj->prev;
	}
	vertex->color = BLACK;
	topologicalOrder[topologicalIndex--] = vertex->name;
	time++;
	vertex->ft = time;
}

void printTopologicalOrder(int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		if (i == 0) printf("\nTopological Order\n%c", topologicalOrder[i]);
		else printf(" -> %c", topologicalOrder[i]);
	}
	printf("\n");
}

void printDfsResults(Vertex graph[], int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		if (i == 0) printf("\n");
		printf("Vertex %c - ", graph[i].name);
		printf("DT %d, ", graph[i].dt);
		printf("FT %d\n", graph[i].ft);
	}
}