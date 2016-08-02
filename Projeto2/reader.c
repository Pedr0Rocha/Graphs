#include <stdio.h>
#include <stdlib.h>
#include "include/reader.h"
#include "include/graph.h"

void readVertexAndEdgeCount(char *path, int *numVertices, int *numEdges) {
	FILE *fp;
	int bytes = 0; 
	
	fp = fopen(path, "r");
	if (fp) 
		bytes = fscanf(fp, "%d %d", numVertices, numEdges);
	else {
		printf("Error reading input file, bytes read = %d\n", bytes);
		exit(1);
	}	
	fclose(fp);
}

void createGraphFromInput(char *path, Vertex graph[], Edge edges[], int numVertices, int numEdges) {
	FILE *fp;
	int vertexName = 0;
	int unnecessaryInfo, // header info already known
		vertexTarget,
		vertexToConectTo;
	int vertexIndex = 0;
	int edgeWeight = 0;

	fp = fopen(path, "r");
	// ignoring info already stored
	fscanf(fp, "%d %d", &unnecessaryInfo, &unnecessaryInfo);

	while (vertexIndex != numVertices)
		initVertex(vertexName++, &graph[vertexIndex++]);
	

	while (numEdges-- > 0) {
		fscanf(fp, " %d %d %d", &vertexToConectTo, &vertexTarget, &edgeWeight);

		connectVertices(&graph[vertexToConectTo], &graph[vertexTarget], edgeWeight);
		addToEdgeArray(edges, numEdges, vertexTarget, vertexToConectTo, edgeWeight);
	}
	printf("\nUndirected Graph Initiated\n");
	
	fclose(fp);
}