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
	ContextManager::Run(bookTable, queueTable, &sortList);
}


void initializeLibrary(HashTable<char*, Book>* bookTable) {
	Book* b1 = new Book((char*)"Flowers for Algernon", (char*)"Flowers for Algernon", (char*)"Daniel Keyes", (char*)"Short Story", 1, 4, 1959, 1);
	Book* b2 = new Book((char*)"Clean Code", (char*)"Clean Code", (char*)"Robert Cecil Martin", (char*)"Non-Fiction", 1, 8, 2008, 1);
	Book* b3 = new Book((char*)"Cat's Cradle", (char*)"Cat's Cradle", (char*)"Kurt Vonnegut", (char*)"Science Fiction", 1, 1, 1963, 1);
	Book* b4 = new Book((char*)"Moby Dick", (char*)"Moby Dick", (char*)"Herman Melville", (char*)"Fiction", 18, 10, 1851, 1);
	Book* b5 = new Book((char*)"I, Robot", (char*)"I, Robot", (char*)"Isaac Asimov", (char*)"Science Fiction", 2, 12, 1950, 1);
	Book* b6 = new Book((char*)"Alice in Wonderland", (char*)"Alice in Wonderland", (char*)"Lewis Carroll", (char*)"Children", 1, 11, 1865, 1);
	Book* b7 = new Book((char*)"World War Z", (char*)"World War Z", (char*)"Max Brooks", (char*)"Apocalyptic", 1, 1, 2006, 1);
	Book* b8 = new Book((char*)"Lord of the Flies", (char*)"Lord of the Flies", (char*)"William Golding", (char*)"Fiction", 17, 9, 1954, 1);
	Book* b9 = new Book((char*)"Jane Eyre", (char*)"Jane Eyre", (char*)"Charlotte Bronte", (char*)"Romance", 19, 10, 1847, 1);
	Book* b10 = new Book((char*)"Gone Girl", (char*)"Gone Girl", (char*)"Gillian Flynn", (char*)"Thriller", 24, 5, 2012, 1);

	bookTable->AddElement(b1->GetId(), b1);
	bookTable->AddElement(b2->GetId(), b2);
	bookTable->AddElement(b3->GetId(), b3);
	bookTable->AddElement(b4->GetId(), b4);
	bookTable->AddElement(b5->GetId(), b5);
	bookTable->AddElement(b6->GetId(), b6);
	bookTable->AddElement(b7->GetId(), b7);
	bookTable->AddElement(b8->GetId(), b8);
	bookTable->AddElement(b9->GetId(), b9);
	bookTable->AddElement(b10->GetId(), b10);
}



