#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/dfs.h"

int time = 0;
int topologicalIndex;
char *topologicalOrder;

void dfs(Vertex graph[], int numVertex) {
	topologicalOrder = malloc(sizeof(char) * numVertex);
	topologicalIndex = numVertex - 1;

	for (int i = 0; i < numVertex; i++)
		if (graph[i].color == WHITE)
			dfsVisit(&graph[i]);
	printTopologicalOrder(numVertex);
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

void printTopologicalOrder(int numVertex) {
	for (int i = 0; i < numVertex; i++) {
		if (i == 0) printf("Topological Order\n%c", topologicalOrder[i]);
		else printf(" -> %c", topologicalOrder[i]);
	}
	printf("\n");
}

void printDfsResults(Vertex graph[], int numVertex) {
	for (int i = 0; i < numVertex; i++) {
		if (i == 0) printf("\n");
		printf("Vertex %c - ", graph[i].name);
		printf("DT %d, ", graph[i].dt);
		printf("FT %d\n", graph[i].ft);
	}
}