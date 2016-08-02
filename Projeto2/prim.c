#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/prim.h"
#include "include/queue.h"

void prim(Vertex graph[], Edge edges[], Vertex *initialVertex, int numVertices, int numEdges) {
	initialVertex->key = 0;

	Queue *Q = createQueue(numVertices);
	for (int i = 0; i < numVertices; i++)
		enqueue(&graph[i], Q);

	printf("Minimum Spawning Tree:\n");
	while(!isEmpty(Q)) {
		Vertex *u = extractMin(Q);
		printf("%d ", u->name);
		AdjList *adj = u->adjList;
		while (adj != NULL) {
			Vertex *v = adj->vertex;
			int weightUtoV = getDistance(edges, u->name, v->name, numEdges);
			if (queueContains(Q, v->name) && weightUtoV < v->key) {
				v->father = u;
				v->key = weightUtoV;
			}
			adj = adj->prev;
		}
	}
}

void printPrimResults(Vertex graph[], int numVertices) {
	for (int i = 0; i < numVertices; i++) {
		if (i == 0) printf("\n");
		printf("Vertex %d - ", graph[i].name);
		printf("Key %d\n", graph[i].key);
	}
}