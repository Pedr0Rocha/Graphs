#ifndef BELLMANFORD_H
#define BELLMANFORD_H
	
int bellmanFord(Vertex graph[], Edge edges[], Vertex *origin, Vertex *goal, int numVertices, int numEdges);
void relax(Vertex *u, Vertex *v, int weight);
void printBellmanFordResults(Vertex graph[], int goalVertex, int numVertices);

#endif