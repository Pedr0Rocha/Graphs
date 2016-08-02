#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>
#include "include/reader.h"
#include "include/graph.h"
#include "include/prim.h"

char *algorithmToRun = NULL;
int isDirected = 0;
int VERTICES_COUNT = 0;
int EDGES_COUNT = 0;
char *path;

void printUsage(){
    printf("\nHelp\n\n");
    printf("Usage: ./graphs <parameter> <value>\n\n");
    printf("  -a <algorithm>     choose the algorithm to run\n");
    printf("  -f <path>          path to input file\n");
    printf("  -i <vertex>        initial vertex\n");
    printf("  -g <vertex>        goal vertex\n\n");
    printf("Algorithms:\n");
    printf("  dfs     Depth-first Search\n");
    printf("  bfs     Breadth-first Search\n");
    printf("  bellman BellmanFord - Shortest Path\n");
    printf("  scc     Strongly-Connected-Components\n\n");
    printf("Example:\n");
    printf("./graphs -a bellman -i 0 -g 4 -f tests/input.txt\n\n");
}

int main(int argc, char **argv) {
	char c;
	int initialVertex;
	int goalVertex;
    while ((c = getopt(argc, argv, "a:f:i:g:h")) != -1) {
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
	        case 'i':
	            initialVertex = atoi(optarg);
	            break;
	        case 'g':
	            goalVertex = atoi(optarg);
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
	readVertexAndEdgeCount(path, &VERTICES_COUNT, &EDGES_COUNT);
	Vertex graph[VERTICES_COUNT];
	Edge edges[EDGES_COUNT];
	createGraphFromInput(path, graph, edges, VERTICES_COUNT, EDGES_COUNT);
	printf("Initial Vertex = %d\n", graph[initialVertex].name);

	if (strcmp(algorithmToRun, "prim") == 0) {
		printf("\nPrim Algorithm\n");
		prim(graph, edges, &graph[initialVertex], VERTICES_COUNT, EDGES_COUNT);
		printf("\n");
	} else if (strcmp(algorithmToRun, "hrt") == 0) {
		printf("\nBreadth-first Search\n");
	} else {
		printf("\nERROR - Incorrect algorithm parameter.\n");
	}
	return 0;
}


