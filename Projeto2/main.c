/* 
	Trabalho de Grafos - Projeto 2
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
#include "include/prim.h"
#include "include/hrt.h"

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
    printf("Algorithms:\n");
    printf("  prim    MST Prim\n");
    printf("  hrt     Heuristic MST\n\n");
    printf("Example:\n");
    printf("./mst -a prim -i 0 -f tests/input.txt\n\n");
}

int main(int argc, char **argv) {
	char c;
	int initialVertex;
	int goalVertex;
    while ((c = getopt(argc, argv, "a:f:i:h")) != -1) {
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
		printf("\nHeuristic Algorithm\n");
		hrt(graph, edges, &graph[initialVertex], VERTICES_COUNT, EDGES_COUNT);
	} else {
		printf("\nERROR - Incorrect algorithm parameter.\n");
	}
	return 0;
}


