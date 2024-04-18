#pragma once
#include "HashTable.h"
#include "DoublyLinkedList.h"
#include "SortedLinkedList.h"
#include "InputWizard.h"
#include <vector>


class Librarian {
public:
	static void AddNewBookToSystem(HashTable<char*, Book>* bookTable, char* bookName, char* bookAuthor, char* bookGenre, int bookDay, int bookMonth, int bookYear, int bookAvailability=1, int bookReviews=0, float bookRatings=0) {

		Book* newBook = new Book(bookName, bookName, bookAuthor, bookGenre, bookDay, bookMonth, bookYear, bookAvailability, bookReviews, bookRatings);
		bookTable->AddElement(newBook->GetId(), newBook);
	}


	static void CreateNavigateList(NavigateList** navList, SortedLinkedList* sortList, int size) {
		std::vector<Book*> values = sortList->GetSortedBooks();
		BookList* head = NULL;
		BookList* tail = NULL;
		for (int i = 0; i < size; i++) {
			AddNewBook(&head, &tail, values[i]);
		}
		(*navList)->head = head;
		(*navList)->tail = tail;
	}

	static void CreateSortedList(SortedLinkedList** sortList, HashTable<char*, Book>* bookTable, char* sortKey) {
		Book** values = bookTable->GetValues();
		SortedLinkedList* newList = new SortedLinkedList(values, sortKey, bookTable->GetSize());
		*sortList = newList;

	}

	static void CreateBookQueue(char* key, int readerID, HashTable<char*, queue>* queueTable) {
		queue* newQueue = initializeQueue();
		enqueue(newQueue, readerID, key);
		queueTable->AddElement(key, newQueue);

	}

	static void AddToBookQueue(char* key, int readerID, HashTable<char*, queue>* queueTable) {
		queue* bookQueue = queueTable->GetElementByKey(key);
		if (bookQueue == NULL) {
			CreateBookQueue(key, readerID, queueTable);
		}
		else {
			queue* bookQueue = queueTable->GetElementByKey(key);
			enqueue(bookQueue, readerID, key);
		}
	}
};