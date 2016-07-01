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

Vertex* dequeue(Queue *queue);
void enqueue(Vertex *v, Queue *queue);
int isEmpty(Queue *queue);
int isFull(Queue *queue);
Queue* createQueue(int maxSize);
void printQueue(Queue *queue);

#endif