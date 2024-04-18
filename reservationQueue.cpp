#include "reservationQueue.h"

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

node* createNewNode(int newReaderID, const char* bookTitle) {
	node* newNode = (node*)malloc(sizeof(node));

	if (newNode == NULL) {
		printf("Error: There is no memory space.\n");
		exit(EXIT_FAILURE);
	}
	
	newNode->readerID = newReaderID;
	newNode->bookTitle = bookTitle;
	newNode->nextNode = NULL;
	
	return newNode;
}

bool isQueueEmpty(queue* queue) {
	return queue->front == NULL;
}

void enqueue(queue* queue, int newReaderID, const char* bookTitle) {
	if (queue == NULL) { // Check if there is a queue at all
		queue = initializeQueue();
	}

	node* nodeToEnqueue = createNewNode(newReaderID, bookTitle);

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

int lengthOfQueue(queue* queue) {
	int length = 0;
	node* current = queue->front;

	if (isQueueEmpty(queue)) {
		return length;
	}

	else {
		while (current != NULL) {
			current = current->nextNode;
			length++;
		}
		
		return length;
	}
}

void showQueue(queue* queue) {

	if (isQueueEmpty(queue)) {
		printf("The queue for %s is empty.\n", queue->front->bookTitle);
		return;
	}

	printf("The reservation queue for -> %s\n", queue->front->bookTitle);
	node* current = queue->front;

	for (int i = 0; i < lengthOfQueue(queue); i++) {
		printf("%d. Reader ID: %d\n", i + 1, current->readerID);
		current = current->nextNode;
	}
	
	printf("\n");

	return;
}

/*
int main(void) {
	queue* queue1 = initializeQueue();

	enqueue(queue1, 11, "Harry Potter");
	enqueue(queue1, 13, "Harry Potter");
	enqueue(queue1, 23, "Harry Potter");
	enqueue(queue1, 32, "Harry Potter");

	printf("The Front Element Is: %d\n", peek(queue1));
	
	int deQueuedElement = dequeue(queue1);

	printf("DeQueued Element Is: %d\n", deQueuedElement);
	printf("The Front Element after DeQueue Is: %d\n", peek(queue1));

	showQueue(queue1);

	free(queue1);
	
	return 0;
}
*/