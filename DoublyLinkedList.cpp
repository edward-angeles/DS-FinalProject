#include "DoublyLinkedList.h"

void AddNewBook(BookList** head, BookList** tail, Book* bookInfo) {
	BookList* newBook = (BookList*)malloc(sizeof BookList);

	if (newBook == NULL) {
		printf("No Memory");
		exit(EXIT_FAILURE);
	}

	newBook->BookInfo = bookInfo;
	newBook->PreviousBook = NULL;
	newBook->NextBook = NULL;

	if (*tail == NULL) {
		(*tail) = newBook;
		*head = newBook;
		return;
	}

	newBook->PreviousBook = *tail;					//books are added to tail to maintain order books are being added in 
	(*tail)->NextBook = newBook;
	*tail = newBook;

}


void PrintBook(struct BookList* current) {
	Book* book = current->BookInfo;
	printf(	
		"Book Information:\n\t"
		"Title: %s\n\t"
		"Author: %s\n\t"
		"Genre: %s\n\t"
		"Publication Date: %d,%d,%d\n\t"
		"Availablity: %d\n\t"
		"Reviews: %d\n\t"
		"Ratings: %f\n", 
		book->GetTitle(), 
		book->GetAuthor(), 
		book->GetGenre(), 
		book->GetPublicationDate().GetDay(), 
		book->GetPublicationDate().GetMonth(),
		book->GetPublicationDate().GetYear(),
		book->GetAvailability(),
		book->GetTotalReviews(),
		book->GetRating()
	);
	printf("-------------\n");
}

void PrintPreviousBook(struct BookList* tail) {
	struct BookList* current = tail->PreviousBook;
	if (tail->PreviousBook == NULL) {
		printf("No Older Books in List");
		return;
	}
	PrintBook(current);
}


void PrintNextBook(struct BookList* tail) {
	struct BookList* current = tail->NextBook;
	if (tail->NextBook == NULL) {
		printf("No Newer Books in List");
		return;
	}
	PrintBook(current);
}

void PrintLastAddedBook(struct BookList* tail) {
	PrintBook(tail);
}


void PrintBookList(struct BookList* tail) {
	struct BookList* current = tail;				//Top of the list will be the last added book
	while (current != NULL) {
		PrintBook(tail);
		current = current->PreviousBook;
	}
}


void DeleteLastAddedBook(struct BookList** head, struct BookList** tail) {
	if (*tail == NULL) {
		printf("List is Empty");			
		return;
	}

	struct BookList* temp = *tail;
	*tail = (*tail)->PreviousBook;

	if (*tail != NULL) {
		(*tail)->NextBook = NULL;

	}
	else {
		*head = NULL;
	}

	free(temp);
}


void FreeList(struct BookList* head) {

	struct BookList* current = head;
	struct BookList* tempNode;

	while (current != NULL) {
		tempNode = current->NextBook
			;
		free(current);
		current = tempNode;
	}

}
