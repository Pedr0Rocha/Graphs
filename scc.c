#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/scc.h"
#include "include/dfs.h"

void dfsScc(Vertex graphT[], Vertex *initialVertex, int numVertices) {
  int componentIndex = 1;
  printf("\nList of Components\n\nComponent %d\n", componentIndex++);
  printf("%c ", initialVertex->name);
  dfsVisitScc(initialVertex);
  for (int i = 0; i < numVertices; i++)
    if (graphT[i].color == WHITE) {
      printf("\n");
      printf("Component %d\n", componentIndex++);
      printf("%c", graphT[i].name);
      dfsVisitScc(&graphT[i]);
    }
  printf("\n");
}

void dfsVisitScc(Vertex *vertex) {
  vertex->color = GRAY;
  AdjList *adj = vertex->adjList;
  while (adj != NULL) {
    Vertex *v = adj->vertex;
    if (v->color == WHITE) {
      printf(" %c", v->name);
      dfsVisitScc(v);
    }
    adj = adj->prev;
  }
  vertex->color = BLACK;
}


void scc(Vertex graph[], int origin, int numVertices) {
	dfs(graph, &graph[origin], numVertices);
	Vertex graphT[numVertices];
	transposeGraph(graph, graphT, numVertices);
	dfsScc(graphT, &graphT[0], numVertices);
}

