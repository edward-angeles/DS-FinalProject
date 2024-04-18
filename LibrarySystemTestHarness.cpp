#include "Book.h"
#include "reservationQueue.h"
#include "HashTable.h"
#include "DoublyLinkedList.h"

#define MENU_ADD_BOOK	 1
#define MENU_NAVIGATE	 2
#define NAV_FORWARD		'w'
#define NAV_BACKWARD	'q'
#define NAV_EXIT		'x'

typedef struct NavigateList {
	struct BookList* head;
	struct BookList* tail;
} NavigateList;


void initializeLibrary(HashTable<char*, Book>* bookTable);
void displayMenu();
void createNavigateList(NavigateList** list, HashTable<char*, Book>* bookTable);

int main(void) {
	HashTable<char*, Book>* bookTable = new HashTable<char*, Book>();
	HashTable<char*, queue>* queueTable = new HashTable<char*, queue>();
	initializeLibrary(bookTable);
	struct BookList* head = NULL;
	struct Booklist* tail = NULL;

	int choice = 0;
	bool run = true;
	while (run) {
		displayMenu();
		printf("Enter your choice: ");
		scanf("%d%*c", &choice);
		printf("%d CHOICE\n", choice);
		switch (choice) {
		case MENU_ADD_BOOK: {
			int bookDay, bookMonth, bookYear, bookAvailability, bookReviews = 0;
			float bookRatings = 0;
			char bookName[50], bookAuthor[50], bookGenre[50], bookDayBuff[3], bookMonthBuff[3], bookYearBuff[5], bookAvailBuff[2], bookReviewBuff[10], bookRatingsBuff[3] = {};
			printf("\nEnter book title: ");
			fgets(bookName, 50, stdin);

			printf("\nEnter book author: ");
			fgets(bookAuthor, 50, stdin);

			printf("\nEnter book Genre: ");
			fgets(bookGenre, 50, stdin);

			printf("\nEnter book publication date: ");
			bookDay = atoi(fgets(bookDayBuff, 3, stdin));
			bookMonth = atoi(fgets(bookMonthBuff, 3, stdin));
			bookYear = atoi(fgets(bookYearBuff, 5, stdin));

			printf("\nEnter book Availablity: ");
			bookAvailability = atoi(fgets(bookAvailBuff, 2, stdin));

			printf("\nEnter book Reviews: ");
			bookReviews = atoi(fgets(bookReviewBuff, 10, stdin));

			printf("\nEnter book Ratings: ");
			bookRatings = atof(fgets(bookRatingsBuff, 3, stdin));

			Book* newBook = new Book(bookName, bookName, bookAuthor, bookGenre, bookDay, bookMonth, bookYear, bookAvailability, bookReviews, bookRatings);
			bookTable->AddElement(newBook->GetId(), newBook);
			break;
		}
		case MENU_NAVIGATE: {
			bool navMode = true;
			NavigateList* navList = (NavigateList*)malloc(sizeof NavigateList);
			if (navList == NULL) {
				exit(EXIT_FAILURE);
			}
			createNavigateList(&navList, bookTable);
			BookList* current = navList->head;
			char navChoice;
			while (navMode) {
				printf("Navigating books\n");
				PrintBook(current);
				printf(
					"\n\nw -> Move Forward\n"
					"q -> Move Backward\n"
					"x -> Exit to main menu\n"
				);
				scanf("%c%*c", &navChoice);


				switch (navChoice) {
				case(NAV_FORWARD): {
					if (current->NextBook != NULL) {
						current = current->NextBook;
					}
					else {
						printf("At end of list\n");
					}
					break;
				}
				case(NAV_BACKWARD): {
					if (current->PreviousBook != NULL) {
						current = current->PreviousBook;
					}
					else {
						printf("At front of list\n");
					}
					break;
				}
				case(NAV_EXIT): {  
					navMode = false;
				}

				}
			};


		}


		default:


			printf("Invalid choice. Please try again.\n");
		}



	}


}


void createNavigateList(NavigateList** list, HashTable<char*, Book>* bookTable) {
	Book** values = bookTable->GetValues();
	BookList* head = NULL;
	BookList* tail = NULL;
	for (int i = 0; i < bookTable->GetSize();i++) {
		AddNewBook(&head, &tail, values[i]);
	} 
	(*list)->head = head;
	(*list)->tail = tail;
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

