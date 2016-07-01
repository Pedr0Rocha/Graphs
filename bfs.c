#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/bfs.h"
#include "include/queue.h"

void bfs(Vertex graph[], Vertex *initialVertex, int numVertex) {
	initialVertex->distance = 0;
	initialVertex->color = GRAY;

	Queue *Q = createQueue(numVertex);
	enqueue(initialVertex, Q);
	while(!isEmpty(Q)) {
		printQueue(Q);
		Vertex *u = dequeue(Q);
		AdjList *adj = u->adjList;
		while (adj != NULL) {
			Vertex *v = adj->vertex;
			if (v->color == WHITE) {
				v->distance = u->distance + 1;
				v->father = u;
				v->color = GRAY;
				enqueue(v, Q);
			}
			adj = adj->prev;
		}
		u->color = BLACK;
		if (isEmpty(Q) && hasUnvisited(graph, numVertex)) {
			Vertex *remaining = getNotVisited(graph, numVertex);
			printf("Remaining %c\n", remaining->name);
			enqueue(remaining, Q);
		}
	}
}

int hasUnvisited(Vertex graph[], int numVertex) {
	for (int i = 0; i < numVertex; i++)
		if (graph[i].color == WHITE) return 1;
	return 0;	
}

Vertex* getNotVisited(Vertex graph[], int numVertex) {
	for (int i = 0; i < numVertex; i++)
		if (graph[i].color == WHITE) return &graph[i];
	return NULL;
}

void printBfsResults(Vertex graph[], int numVertex) {
	for (int i = 0; i < numVertex; i++) {
		if (i == 0) printf("\n");
		printf("Vertex %c - ", graph[i].name);
		printf("Distance %d\n", graph[i].distance);
	}
}