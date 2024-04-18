#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <new.h>

using namespace std;

typedef struct QueueNode {
	int readerID;
	QueueNode* nextNode;
	const char* bookTitle;
} QueueNode;

typedef struct Queue {
	QueueNode* front;
	QueueNode* rear;
} queue;


queue* initializeQueue(void); // Initializes an empty queue
QueueNode* createNewNode(int newReaderID, const char* bookTitle); // creates a new node 
bool isQueueEmpty(queue* queue); // Checks if the queue is empty
void enqueue(queue* queue, int newReaderID, const char* bookTitle); // Adds a new reader to the queue to wait for a book 
int dequeue(queue* queue); // Deletes the first reader after the book is returned
int peek(queue* queue); // Returns the first readers's ID who has the book 
void showQueue(queue* queue); // Shows the queue to hold a book
int lengthOfQueue(queue* queue); // Shows the size of the queue
