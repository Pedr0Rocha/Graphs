#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include "include/reader.h"
#include "include/graph.h"
#include "include/dfs.h"
#include "include/bfs.h"

int isDirected = 1;
int VERTICES_COUNT = 0;
int EDGES_COUNT = 0;
char *path = "tests/input1.txt";

int main(int argc, char **argv) {
	readVertexAndEdgeCount(path, &VERTICES_COUNT, &EDGES_COUNT);

	Vertex graph[VERTICES_COUNT];
	createGraphFromInput(path, graph, VERTICES_COUNT, EDGES_COUNT, isDirected);
	//dfs(graph, VERTICES_COUNT);
	//printf("\nDepth-first Search\n");
	//printDfsResults(graph, VERTICES_COUNT);


	printf("\nBreadth-first Search\n");
	bfs(graph, &graph[0], VERTICES_COUNT);
	printBfsResults(graph, VERTICES_COUNT);
	return 0;
}
