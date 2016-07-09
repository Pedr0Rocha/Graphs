#ifndef BELLMANFORD_H
#define BELLMANFORD_H
	
int bellmanFord(Vertex graph[], Edge edges[], int origin, Vertex *goal, int numVertices, int numEdges);
void relax(Vertex *u, Vertex *v, int weight);
void printBellmanFordResults(Vertex graph[], int numVertices);

#endif