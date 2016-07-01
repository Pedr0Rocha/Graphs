#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/queue.h"

Vertex* dequeue(Queue *queue) {
	if (!isEmpty(queue)) {
		Vertex *v = queue->vertexQueue[queue->first];
		queue->first++;
		queue->size--;
		return v;
	}
	return NULL;
}

void enqueue(Vertex *v, Queue *queue) {
	if (!isFull(queue)) {
		queue->vertexQueue[queue->last] = v;
		queue->last++;
		queue->size++;
	}
}

int isEmpty(Queue *queue) {
	if (queue->size == 0) return 1;
	return 0;
}

int isFull(Queue *queue) {
	if (queue->size == queue->maxSize) return 1;
	return 0;
}

Queue* createQueue(int maxSize) {
	Queue *queue = malloc(sizeof(Queue));
	*queue = (Queue) {
		.vertexQueue = malloc(sizeof(Vertex *) * maxSize),
		.first = 0,
		.last = 0,
		.maxSize = maxSize,
		.size = 0
	};
	return queue;
}

void printQueue(Queue *queue) {
	for (int i = 0; i < queue->maxSize; i++)
		printf("%c -> ", queue->vertexQueue[i]->name);
}