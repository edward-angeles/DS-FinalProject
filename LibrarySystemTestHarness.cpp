#include "Book.h"
#include "reservationQueue.h"
#include "HashTable.h"

void initializeLibrary(HashTable<char*, Book>* bookTable);


int main(void) {
	HashTable<char*, Book>* bookTable = new HashTable<char*, Book>;
	queue* holdQueue = initializeQueue();
	initializeLibrary(bookTable);

	printf("%s", (*bookTable->GetElementByKey((char*)"h")).GetAuthor());
	printf("%s", (*bookTable->GetElementByKey((char*)"book2")).GetAuthor());

	bookTable->DeleteElementByKey((char*)"book2");

	printf("%s", (*bookTable->GetElementByKey((char*)"h")).GetAuthor());
	//printf("%s", (*bookTable->GetElementByKey((char*)"book2")).GetAuthor());
	bookTable->GetElementByKey((char*)"book2");
}


void initializeLibrary(HashTable<char*, Book>* bookTable) {
	Book* b1 = new Book((char*) "h", (char*) "Flowers for Algernon", (char*) "Daniel Keyes", (char*) "Short Story", 1, 4, 1959, 1);
	Book* b2 = new Book((char*)"book2", (char*) "Clean Code", (char*) "Robert Cecil Martin", (char*) "Non-Fiction", 1, 8, 2008, 1);
	bookTable->AddElement(b1->GetId(), b1);
	bookTable->AddElement(b2->GetId(), b2);
}

