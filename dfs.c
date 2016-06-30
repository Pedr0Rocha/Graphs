#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/dfs.h"

int time = 0;

void dfs(Vertex graph[], int numVertex) {
	for (int i = 0; i < numVertex; i++)
		if (graph[i].color == WHITE)
			dfsVisit(&graph[i]);
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
	printf("Topological Order: %c\n", vertex->name);
	time++;
	vertex->ft = time;
}

