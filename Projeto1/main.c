/* 
	Trabalho de Grafos - Projeto 1 
	Pedro Rocha   - RA 68740
	Marcos Felipe - RA 71831
*/ 

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
#include "include/bellmanford.h"
#include "include/scc.h"

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
	readVertexAndEdgeCount(path, &VERTICES_COUNT, &EDGES_COUNT, &isDirected);
	Vertex graph[VERTICES_COUNT];
	Edge edges[EDGES_COUNT];
	createGraphFromInput(path, graph, edges, VERTICES_COUNT, EDGES_COUNT, isDirected);
	printf("Initial Vertex = %c\n", graph[initialVertex].name);

	if (strcmp(algorithmToRun, "dfs") == 0) {
		dfs(graph, &graph[initialVertex], VERTICES_COUNT);
		printf("\nDepth-first Search\n");
		printDfsResults(graph, VERTICES_COUNT);

	} else if (strcmp(algorithmToRun, "bfs") == 0) {
		printf("\nBreadth-first Search\n");
		bfs(graph, &graph[initialVertex], VERTICES_COUNT);
		printBfsResults(graph, VERTICES_COUNT);

	} else if (strcmp(algorithmToRun, "bellman") == 0) {
		printf("\nBellman-Ford - ");
		printf("Goal Vertex - %c\n", graph[goalVertex].name);
		int noNegativeCycle = bellmanFord(graph, edges, initialVertex, VERTICES_COUNT, EDGES_COUNT);
		if (noNegativeCycle)
			printBellmanFordResults(graph, VERTICES_COUNT, goalVertex);
		else
			printf("Negative Cycle Found!\n");

	} else if (strcmp(algorithmToRun, "scc") == 0) {
		printf("\nStrongly-Connected-Components\n");
		scc(graph, initialVertex, VERTICES_COUNT);
		
	} else {
		printf("\nERROR - Incorrect algorithm parameter.\n");
	}
	return 0;
}


