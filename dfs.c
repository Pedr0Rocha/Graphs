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
	for (int i = 0; i < vertex->adjListSize-1; i++){
		if (vertex->adjList[i].vertex->color == WHITE){
			vertex->adjList[i].vertex->father = vertex;
			dfsVisit(vertex->adjList[i].vertex);
		}
	}
	vertex->color = BLACK;
	time++;
	vertex->ft = time;
}

