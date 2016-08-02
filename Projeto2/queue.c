#include <stdio.h>
#include <stdlib.h>
#include "include/graph.h"
#include "include/queue.h"

Vertex* extractMin(Queue *queue) {
	if (!isEmpty(queue)) {
		Vertex *v = queue->vertexQueue[findMin(queue)];
		v->visited = 1;
		return v;
	}
	return NULL;
}

int findMin(Queue *queue) {
	int min = 9999;
	int minIndex = -1;
	for (int i = 0; i < queue->size; i++)
		if (queue->vertexQueue[i]->key < min && !queue->vertexQueue[i]->visited) {
			min = queue->vertexQueue[i]->key;
			minIndex = i;
		}
	return minIndex;
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
	for (int i = 0; i < queue->size; i++)
		if (!queue->vertexQueue[i]->visited) return 0;
	return 1;
}

int isFull(Queue *queue) {
	if (queue->size == queue->maxSize) return 1;
	return 0;
}

int queueContains(Queue *queue, int name) {
	for (int i = 0; i < queue->size; i++)
		if (queue->vertexQueue[i]->name == name) 
			if (!queue->vertexQueue[i]->visited) return 1;
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
	for (int i = 0; i < queue->size; i++)
		printf("%d (%d)-> ", queue->vertexQueue[i]->name, queue->vertexQueue[i]->visited);
}