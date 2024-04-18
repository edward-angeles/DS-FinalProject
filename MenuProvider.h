#pragma once

#include <stdlib.h>
#include "HashTable.h"
#include "reservationQueue.h"
#include "Librarian.h"
#include "DoublyLinkedList.h"
#include "SortedLinkedList.h"


#define MENU_ADD_BOOK		1
#define MENU_NAVIGATE		2
#define MENU_EXIT			3

#define NAV_FORWARD			'w'
#define NAV_BACKWARD		'q'
#define NAV_SORT			's'
#define NAV_EXIT			'x'
#define NAV_QUEUE			'p'

#define SORT_TITLE				1
#define SORT_AUTHOR				2
#define SORT_GENRE				3
#define SORT_PUBLICATION_DATE	4
#define SORT_AVAILABILITY		5
#define SORT_REVIEWS			6
#define SORT_RATINGS			7
#define SORT_EXIT				8

#define CONTEXT_MAIN		100
#define CONTEXT_ADD			101
#define CONTEXT_NAV			102
#define CONTEXT_SORT		103
#define CONTEXT_EXIT		104



class MenuProvider {

public:
	static int MainMenu(HashTable<char*, Book>* bookTable) {
		int choice = 0;
		bool run = true;
		while (run) {
			DisplayMain();

			InputWizard::GetIntNoBuffer("Enter your choice: ", &choice);
	
			switch (choice) {
			case MENU_ADD_BOOK: {
				return CONTEXT_ADD;
			}

			case MENU_NAVIGATE: {
				return CONTEXT_NAV;
			}

			case MENU_EXIT: {
				return CONTEXT_EXIT;
			}
			default:

				printf("Invalid choice. Please try again.\n");
			}

		}


	
	}

	static int NavigateMenu(HashTable<char*, Book>* bookTable, HashTable<char*, queue>* queueTable, SortedLinkedList* sortList) {
		bool navMode = true;
		NavigateList* navList = (NavigateList*)malloc(sizeof NavigateList);
		if (navList == NULL) {
			exit(EXIT_FAILURE);
		}
		Librarian::CreateNavigateList(&navList, sortList, bookTable->GetSize());
		BookList* current = navList->head;
		char navChoice;

		while (navMode) {
			printf("Navigating books\n");
			PrintBook(current);
			DisplayNav();
			InputWizard::GetCharNoBuffer(" ", &navChoice);


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
			case(NAV_SORT): {
				return CONTEXT_SORT;
			}

			case(NAV_QUEUE): {
				QueueMenu(bookTable, queueTable, current->BookInfo);
				break;
			}

			case(NAV_EXIT): {
				return CONTEXT_MAIN;
			}

			}
		};
	}

	static int AddNewBookMenu(HashTable<char*, Book>* bookTable) {
		int bookDay, bookMonth, bookYear, bookAvailability, bookReviews = 0;
		float bookRatings = 0;
		char bookName[50], bookAuthor[50], bookGenre[50], bookDayBuff[3], bookMonthBuff[3], bookYearBuff[5], bookAvailBuff[2], bookReviewBuff[10], bookRatingsBuff[3] = {};
		InputWizard* gandalf = new InputWizard();

		gandalf->GetBufferedInput("\nEnter book title: ", bookName);
		gandalf->GetBufferedInput("\nEnter book author: ", bookAuthor);
		gandalf->GetBufferedInput("\nEnter book Genre: ", bookGenre);
		gandalf->GetBufferedInput("\nEnter book publication day: ", bookDayBuff);
		gandalf->GetBufferedInput("\nEnter book publication month: ", bookMonthBuff);
		gandalf->GetBufferedInput("\nEnter book publication year: ", bookYearBuff);
		gandalf->GetBufferedInput("\nEnter book Availablity: ", bookAvailBuff);
		gandalf->GetBufferedInput("\nEnter book Reviews: ", bookReviewBuff);
		gandalf->GetBufferedInput("\nEnter book Ratings: ", bookRatingsBuff);


		bookDay = atoi(bookDayBuff);
		bookMonth = atoi(bookMonthBuff);
		bookYear = atoi(bookYearBuff);
		bookAvailability = atoi(bookAvailBuff);
		bookReviews = atoi(bookReviewBuff);
		bookRatings = atof(bookRatingsBuff);
		Librarian::AddNewBookToSystem(bookTable, bookName, bookAuthor, bookGenre, bookDay, bookMonth, bookYear, bookAvailability, bookReviews, bookRatings);
		return CONTEXT_MAIN;
	}

	static int SortMenu(HashTable<char*, Book>* bookTable, SortedLinkedList** sortList) {
		int choice = 0;
		bool run = true;
		DisplaySort();
		char sortKey[50] = {};
		InputWizard::GetIntNoBuffer(" ", &choice);

		switch (choice) {
		case SORT_TITLE: {
			strcpy(sortKey, "title");
			break;
		}
		case SORT_AUTHOR: {
			strcpy(sortKey, "author");
			break;
		}
		case SORT_GENRE: {
			strcpy(sortKey, "genre");
			break;
		}
		case SORT_PUBLICATION_DATE: {
			strcpy(sortKey, "date");
			break;
		}
		case SORT_AVAILABILITY: {
			strcpy(sortKey, "availability");
			break;
		}
		case SORT_REVIEWS: {
			strcpy(sortKey, "reviews");
			break;
		}
		case SORT_RATINGS: {
			strcpy(sortKey, "ratings");
			break;
		}
		default:
			printf("Invalid input, try again");
			break;
		}

		if (strcmp(sortKey, "N/A") != 0) {
			Librarian::CreateSortedList(sortList, bookTable, sortKey);
			return CONTEXT_NAV;
		}

	}


	static void QueueMenu(HashTable<char*, Book>* bookTable, HashTable<char*, queue>* queueTable, Book* bookToHold) {
		char readerIdBuff[10] = {};
		InputWizard::GetBufferedInput("\nEnter Reader ID: ", readerIdBuff);
		Librarian::AddToBookQueue(bookToHold->GetId(), atoi(readerIdBuff), queueTable);
		
	
	}

	static void DisplaySort() {
		printf(
			"\n\nSort By:\n"
			"1 -> Title\n"
			"2 -> Author\n"
			"3 -> Genre\n"
			"4 -> Publication Date\n"
			"5 -> Availability\n"
			"6 -> Reviews\n"
			"7 -> Ratings\n\n"
			"8 -> Cancel\n"
		);
	}

	static void DisplayMain() {
		printf(
				"\nMenu:\n"
				"1. Add Book to System\n"
				"2. View Books in System\n"
				"3. Exit\n"
		);
	}

	static void DisplayNav() {
		printf(
			"\n\nw -> Move Forward\n"
			"q -> Move Backward\n"
			"s -> Sort\n"
			"p -> Place Hold On Current Book\n"
			"x -> Exit to main menu\n"
		);
	}
};
