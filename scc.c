#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/scc.h"
#include "include/dfs.h"

int compare (const void * a, const void * b) {
  Vertex *u = (Vertex *)a;
  Vertex *v = (Vertex *)b;

  printf("u = %d , v = %d\n", u->ft, v->ft);
  if (u->ft < v->ft) return -1;
  else if (u-> ft > v->ft) return 1;
  else return 0;
}

void scc(Vertex graph[], int origin, int numVertices) {
	dfs(graph, &graph[origin], numVertices);
	Vertex graphT[numVertices];
	transposeGraph(graph, graphT, numVertices);
	qsort(graphT, numVertices, sizeof(Vertex), compare);
	dfsScc(graphT, &graphT[0], numVertices);
}

