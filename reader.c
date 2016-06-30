#include <stdio.h>
#include <stdlib.h>
#include "include/reader.h"
#include "include/graph.h"

int readVertexCount(char *path) {
	FILE *fp;

	int bytes, numVertex = 0;
	
	fp = fopen(path, "r");
	if (fp != NULL){
		bytes = fscanf(fp, "%d", &numVertex);
	} else {
		printf("Error reading input file. Bytes = %d", bytes);
		fclose(fp);
		exit(1);
	}	
	return numVertex;
}


void createGraphFromInput(char *path, Vertex graph[]) {
	FILE *fp;
	int graphCounter = 0;
	char name;

	fp = fopen(path, "r");
	fscanf(fp, "%c", &name);
	fscanf(fp, "%c", &name);

	while (graphCounter){
		if (name == '|') continue;
		printf("Vertex Name: %c\n", name);
		initVertex(name, &graph[graphCounter++]);
		if (graphCounter > 10) break;				
	}

	fclose(fp);
}