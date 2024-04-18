#include "Book.h"
#include "reservationQueue.h"
#include "HashTable.h"
#include "DoublyLinkedList.h"
#include "Librarian.h"
#include "ContextManager.h"



void initializeLibrary(HashTable<char*, Book>* bookTable);


int main(void) {
	HashTable<char*, Book>* bookTable = new HashTable<char*, Book>();
	initializeLibrary(bookTable);
	HashTable<char*, queue>* queueTable = new HashTable<char*, queue>();
	SortedLinkedList* sortList = new SortedLinkedList(bookTable->GetValues(), (char*) "title", bookTable->GetSize());
	ContextManager().Run(bookTable, queueTable, &sortList);
}


void initializeLibrary(HashTable<char*, Book>* bookTable) {
	Book* b1 = new Book((char*)"Flowers for Algernon", (char*)"Flowers for Algernon", (char*)"Daniel Keyes", (char*)"Short Story", 1, 4, 1959, 1);
	Book* b2 = new Book((char*)"Clean Code", (char*)"Clean Code", (char*)"Robert Cecil Martin", (char*)"Non-Fiction", 1, 8, 2008, 1);
	Book* b3 = new Book((char*)"Cat's Cradle", (char*)"Cat's Cradle", (char*)"Kurt Vonnegut", (char*)"Science Fiction", 1, 1, 1963, 1);
	Book* b4 = new Book((char*)"Moby Dick", (char*)"Moby Dick", (char*)"Herman Melville", (char*)"Fiction", 18, 10, 1851, 1);
	bookTable->AddElement(b1->GetId(), b1);
	bookTable->AddElement(b2->GetId(), b2);
	bookTable->AddElement(b3->GetId(), b3);
	//bookTable->AddElement(b4->GetId(), b4);

}



