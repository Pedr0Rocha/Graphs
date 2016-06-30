#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include "include/reader.h"
#include "include/graph.h"
#include "include/dfs.h"

int NUMVERTEX = 6;
int NUMEDGES = 0;
char *path = "tests/input1.txt";

void manuallyCreateGraph(Vertex graph[]) {
	initVertex('U', &graph[0]);
	initVertex('V', &graph[1]);
	initVertex('W', &graph[2]);
	initVertex('X', &graph[3]);
	initVertex('Y', &graph[4]);
	initVertex('Z', &graph[5]);
	printf("Vertex Initiated\n");

	addToAdjList(&graph[0], &graph[3]);
	addToAdjList(&graph[0], &graph[1]);
	addToAdjList(&graph[1], &graph[4]);
	addToAdjList(&graph[2], &graph[5]);
	addToAdjList(&graph[2], &graph[4]);
	addToAdjList(&graph[3], &graph[1]);
	addToAdjList(&graph[4], &graph[3]);
	addToAdjList(&graph[5], &graph[5]);
	printf("Vertex Connected\n\n");
}

int main(int argc, char **argv) {
	//NUMVERTEX = readVertexCount(path);

	Vertex graph[NUMVERTEX];
	manuallyCreateGraph(graph);
	//createGraphFromInput(path, graph);

	dfs(graph, NUMVERTEX);
	for (int i = 0; i < NUMVERTEX; i++) {
		if (i == 0) printf("\n");
		printf("Vertex %c - ", graph[i].name);
		printf("DT %d, ", graph[i].dt);
		printf("FT %d\n", graph[i].ft);
	}
	return 0;
}
