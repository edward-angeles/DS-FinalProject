#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <new.h>

typedef struct Node {
	int readerID;
	Node* nextNode;
} node;

typedef struct Queue {
	node* front; 
	node* rear;
} queue;


queue* initializeQueue(void); // Initializes an empty queue
node* createNewNode(int newReaderID); // creates a new node 
bool isQueueEmpty(queue* queue); // Checks if the queue is empty
void enqueue(queue* queue, int newReaderID); // Adds a new reader to the queue to wait for a book 
int dequeue(queue* queue); // Deletes the first reader after the book is returned
int peek(queue* queue); // Returns the first readers's ID who has the book 
void showQueue(queue* queue); // Shows the queue to hold a book

