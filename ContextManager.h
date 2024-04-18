#pragma once
#include "MenuProvider.h";



class ContextManager {
public:
	static void Run(HashTable<char*, Book>* bookTable, HashTable<char*, queue>* queueTable, SortedLinkedList** sortedList) {
		MenuProvider* menuProvider = new MenuProvider();
		int currentContext = CONTEXT_MAIN;
		bool run = true;
		while (run) {
			switch (currentContext) {
			case CONTEXT_MAIN: {
				currentContext = menuProvider->MainMenu(bookTable);
				break;
			}
			case CONTEXT_ADD: {
				currentContext = menuProvider->AddNewBookMenu(bookTable);
				break;
			}
			case CONTEXT_NAV: {
				currentContext = menuProvider->NavigateMenu(bookTable, queueTable, *sortedList);
				break;
			}
			case CONTEXT_SORT: {
				currentContext = menuProvider->SortMenu(bookTable, sortedList);
				break;
			}
			case CONTEXT_EXIT: {
				return;
			}
			default:
				printf("Invalid Input. Try again.");
			}
		}
	}
};