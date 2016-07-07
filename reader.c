#include <stdio.h>
#include <stdlib.h>
#include "include/reader.h"
#include "include/graph.h"

void readVertexAndEdgeCount(char *path, int *numVertices, int *numEdges, int *isDirected) {
	FILE *fp;
	int bytes = 0; 
	
	printf("Path = %s\n", path);
	fp = fopen(path, "r");
	if (fp != NULL) {
		bytes = fscanf(fp, "%d %d %d", numVertices, numEdges, isDirected);
	} else {
		printf("Error reading input file. Bytes = %d", bytes);
		fclose(fp);
		exit(1);
	}	
	fclose(fp);
}

void createGraphFromInput(char *path, Vertex graph[], int numVertices, int numEdges, int directed) {
	FILE *fp;
	char vertexName;
	int unnecessaryInfo, // header info already known
		vertexTarget,
		vertexToConectTo;
	int vertexIndex = 0;

	fp = fopen(path, "r");
	fscanf(fp, "%d %d %d", &unnecessaryInfo, &unnecessaryInfo, &unnecessaryInfo);

	while (vertexIndex != numVertices) {
		fscanf(fp, " %c", &vertexName);
		initVertex(vertexName, &graph[vertexIndex++]);
	}

	while (numEdges-- >= 0) {
		fscanf(fp, " %d %d", &vertexToConectTo, &vertexTarget);
		if (directed)
			addToAdjList(&graph[vertexToConectTo], &graph[vertexTarget]);
		else
			connectVertices(&graph[vertexToConectTo], &graph[vertexTarget]);
	}
	if (directed)
		printf("\nDirected Graph Initiated\n");
	else
		printf("\nUndirected Graph Initiated\n");
	fclose(fp);
}