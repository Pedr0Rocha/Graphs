#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include "include/reader.h"
#include "include/graph.h"
#include "include/dfs.h"
#include "include/bfs.h"

char *algorithmToRun = NULL;
int isDirected = 0;
int VERTICES_COUNT = 0;
int EDGES_COUNT = 0;
char *path;

void printUsage(){
    printf("\nHelp\n\n");
    printf("Usage: ./a.out <parameter> <value>\n\n");
    printf("  -a <algorithm>     choose the algorithm to run\n");
    printf("  -f <path>          path to input file\n\n");
    printf("Algorithms:\n");
    printf("  dfs     Depth-first search\n");
    printf("  bfs     Breadth-first search\n\n");
    printf("Example:\n");
    printf("./a.out -a dfs -f tests/input1.txt\n\n");
}

int main(int argc, char **argv) {
	char c;
    while ((c = getopt(argc, argv, "a:f:h")) != -1) {
	    switch (c){
	        case 'a':
	            algorithmToRun = optarg;
	            if (!algorithmToRun){
	            	printUsage();
	            	exit(1);
	            }
	            break;
	        case 'f':
	            path = optarg;
	            break;
	        case 'h':
	            printUsage();
	            exit(0);
	        case '?':
	            printf("Error reading parameters.\n");
	        default:
	            abort();
	    }
	}
	readVertexAndEdgeCount(path, &VERTICES_COUNT, &EDGES_COUNT, &isDirected);
	Vertex graph[VERTICES_COUNT];
	createGraphFromInput(path, graph, VERTICES_COUNT, EDGES_COUNT, isDirected);

	if (strcmp(algorithmToRun, "dfs") == 0) {

		dfs(graph, &graph[0], VERTICES_COUNT);
		printf("\nDepth-first Search\n");
		printDfsResults(graph, VERTICES_COUNT);

	} else if (strcmp(algorithmToRun, "bfs") == 0) {

		printf("\nBreadth-first Search\n");
		bfs(graph, &graph[0], VERTICES_COUNT);
		printBfsResults(graph, VERTICES_COUNT);
	} else {
		printf("\nERROR - Incorrect algorithm parameter.\n");
	}
	return 0;
}


