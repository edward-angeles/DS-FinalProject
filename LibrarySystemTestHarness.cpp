#include "Book.h"
#include "reservationQueue.h"
#include "HashTable.h"

void initializeLibrary(HashTable<char*, Book>* bookTable);
void displayMenu();

int main(void) {
	HashTable<char*, Book>* bookTable = new HashTable<char*, Book>;
	initializeLibrary(bookTable);
	struct BookList* head = NULL;
	struct Booklist* tail = NULL;

	int choice = 0;
	bool run = true;
	while (run) {
		displayMenu();
		printf("Enter your choice: ");
		scanf("%d", choice);

		switch (choice) {
		case 1:
			int bookDay, bookMonth, bookYear, bookAvailablity, bookReviews = 0;
			float bookRatings = 0;
			char bookName[50], bookAuthor[50], bookGenre[50] = {};
			printf("\nEnter book title: ");
			scanf("%49s", bookName);

			printf("\nEnter book author: ");
			scanf("%49s", bookAuthor);

			printf("\nEnter book Genre: ");
			scanf("%49s", bookGenre);

			printf("\nEnter book publication date: ");
			scanf("%49d", bookDay);
			scanf("%49d", bookMonth);
			scanf("%49d", bookYear);

			printf("\nEnter book Availablity: ");
			scanf("%49d", bookAvailablity);

			printf("\nEnter book Reviews: ");
			scanf("%49d", bookReviews);

			printf("\nEnter book Ratings: ");
			scanf("%1.1f", bookRatings);

			Book* newBook = new Book(bookName, bookName, bookAuthor, bookGenre, bookDay, bookMonth, bookYear, bookAvailablity, bookReviews, bookRatings);
			bookTable->AddElement(newBook->GetId(), newBook);

		default:


			printf("Invalid choice. Please try again.\n");
		}



	}


}


void initializeLibrary(HashTable<char*, Book>* bookTable) {
	Book* b1 = new Book((char*)"h", (char*)"Flowers for Algernon", (char*)"Daniel Keyes", (char*)"Short Story", 1, 4, 1959, 1);
	Book* b2 = new Book((char*)"book2", (char*)"Clean Code", (char*)"Robert Cecil Martin", (char*)"Non-Fiction", 1, 8, 2008, 1);
	bookTable->AddElement(b1->GetId(), b1);
	bookTable->AddElement(b2->GetId(), b2);
}

void displayMenu() {
	printf("\nMenu:\n");
	printf("1. Add Book to System\n");
	printf("2. View Books in System\n");
	printf("3. Manage Books in Holding Queue\n");
	printf("4. Exit\n");
}

