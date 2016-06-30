#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include "include/reader.h"
#include "include/graph.h"
#include "include/dfs.h"

int numVertex = 0;
char *path = "tests/input1.txt";

void manuallyCreateGraph(Vertex graph[]){
	initVertex('A', &graph[0]);
	initVertex('B', &graph[1]);
	initVertex('C', &graph[2]);
	printf("Vertex Initiated\n");

	connectVertex(&graph[0], &graph[1]);
	connectVertex(&graph[0], &graph[2]);
	connectVertex(&graph[1], &graph[2]);
	printf("Vertex Connected\n");
}

int main(int argc, char **argv) {

	numVertex = readVertexCount(path);

	Vertex graph[numVertex];
	manuallyCreateGraph(graph);
	//createGraphFromInput(path, graph);

	dfs(graph, numVertex);
	for (int i = 0; i < numVertex; i++){
		printf("Vertex %c\n", graph[i].name);
		printf("Discovery Time %d\n", graph[i].dt);
		printf("Final Time %d\n\n", graph[i].ft);
	}
	return 0;
}
