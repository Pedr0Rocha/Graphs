#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include "include/reader.h"
#include "include/graph.h"
#include "include/dfs.h"

int numVertex = 6;
char *path = "tests/input1.txt";

void manuallyCreateGraph(Vertex graph[]){
	initVertex('A', &graph[0]);
	initVertex('B', &graph[1]);
	initVertex('C', &graph[2]);
	initVertex('D', &graph[3]);
	initVertex('F', &graph[4]);
	initVertex('G', &graph[5]);
	printf("Vertex Initiated\n");

	connectVertex(&graph[0], &graph[1]);
	connectVertex(&graph[0], &graph[2]);
	connectVertex(&graph[1], &graph[2]);
	connectVertex(&graph[3], &graph[2]);
	connectVertex(&graph[4], &graph[5]);
	connectVertex(&graph[0], &graph[4]);
	for (int i = 0; i < numVertex; i++){
		printf("%c Adj Size: %d\n", graph[i].name, graph[i].adjListSize);
		AdjList *adj = graph[i].adjList;
		while (adj != NULL){
			printf("Adj -> %c\n", adj->vertex->name);
			adj = adj->prev;
		}
	}
	printf("Vertex Connected\n");
}

int main(int argc, char **argv) {
	//numVertex = readVertexCount(path);

	Vertex graph[numVertex];
	manuallyCreateGraph(graph);
	//createGraphFromInput(path, graph);

	dfs(graph, numVertex);
	for (int i = 0; i < numVertex; i++){
		printf("\nVertex %c\n", graph[i].name);
		printf("Discovery Time %d\n", graph[i].dt);
		printf("Final Time %d\n", graph[i].ft);
	}
	return 0;
}
