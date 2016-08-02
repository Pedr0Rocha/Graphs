#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

typedef struct Queue Queue;

struct Queue {
	Vertex **vertexQueue;
	int first, 
		last,
		size,
		maxSize;
};

void enqueue(Vertex *v, Queue *queue);
int isEmpty(Queue *queue);
int isFull(Queue *queue);
int findMin(Queue *queue);
int queueContains(Queue *queue, int name);
Queue* createQueue(int maxSize);
Vertex* extractMin(Queue *queue);
void printQueue(Queue *queue);

#endif