#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/scc.h"
#include "include/dfs.h"

void scc(Vertex graph[], int origin, int numVertices) {
	dfs(graph, &graph[origin], numVertices);
	transposeGraph(graph, numVertices);
	sortByFinalTime(graph, numVertices);
	dfs(graph, &graph[0], numVertices);
}

