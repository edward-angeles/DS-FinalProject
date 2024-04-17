#include "bookHolding.h"

queue* initializeQueue(void) {
	queue* newQueue = (queue*)malloc(sizeof(queue));

	if (newQueue == NULL) {
		printf("Error: There is no memory space.\n");
		exit(EXIT_FAILURE);
	}

	newQueue->front = NULL;
	newQueue->rear = NULL;
	
	return newQueue;
}

node* createNewNode(int newReaderID) {
	node* newNode = (node*)malloc(sizeof(node));

	if (newNode == NULL) {
		printf("Error: There is no memory space.\n");
		exit(EXIT_FAILURE);
	}
	
	newNode->readerID = newReaderID;
	newNode->nextNode = NULL;
	
	return newNode;
}

bool isQueueEmpty(queue* queue) {
	return queue->front == NULL;
}

void enqueue(queue* queue, int newReaderID) {
	if (queue == NULL) { // Check if there is a queue at all
		queue = initializeQueue();
	}

	node* nodeToEnqueue = createNewNode(newReaderID);

	if (isQueueEmpty(queue)) { // Check if the queue is empty
		queue->front = nodeToEnqueue;
	}
	
	else {
		queue->rear->nextNode = nodeToEnqueue; 
	}

	queue->rear = nodeToEnqueue;
}

int dequeue(queue* queue) {
	if (isQueueEmpty(queue)) {
		printf("Error: The queue is empty.\n");
		return EXIT_FAILURE;
	}

	node* nodeToDequeue = queue->front;
	int dataToDequeue = nodeToDequeue->readerID;
	queue->front = nodeToDequeue->nextNode;
	
	if (queue->front == NULL) {    // Check if there is a next node
		queue->rear = NULL;		   // If new front is null, then rear is as well null
	}

	free(nodeToDequeue);
	return dataToDequeue;
}

int peek(queue* queue) {
	if (isQueueEmpty(queue)) {
		printf("Error: The queue is empty.\n");
		return EXIT_FAILURE;
	}
	return queue->front->readerID;
}

void showQueue(queue* queue) {

	if (isQueueEmpty(queue)) {
		printf("The queue for this book is empty.\n");
		return;
	}

	printf("Queue For Book Hold:\n");
	node* current = queue->front;

	while (current != NULL) {
		printf("Reader ID: %d\n", current->readerID);
		current = current->nextNode;
	}
	
	printf("\n");
}


int main(void) {
	queue* queue1 = initializeQueue();

	enqueue(queue1, 11);
	enqueue(queue1, 13);
	enqueue(queue1, 23);
	enqueue(queue1, 32);

	printf("The Front Element Is: %d\n", peek(queue1));

	int deQueuedElement = dequeue(queue1);

	printf("DeQueued Element Is: %d\n", deQueuedElement);
	printf("The Front Element after DeQueue Is: %d\n", peek(queue1));

	showQueue(queue1);

	free(queue1);

	return 0;
}
