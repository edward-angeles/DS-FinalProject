#pragma once

#include "Book.h"
#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>

struct BookList {
	Book* BookInfo;
	struct BookList* PreviousBook;
	struct BookList* NextBook;
} temp;

void AddNewBook(struct BookList** head, struct BookList** tail, Book* bookInfo);

void PrintBookList(struct BookList* head);

void DeleteLastAddedBook(struct BookList** head, struct BookList** tail);

void FreeList(struct BookList* head);

void PrintLastAddedBook(struct BookList* tail);

void PrintBook(struct BookList* tail);

void PrintPreviousBook(struct BookList* tail);

void PrintNextBook(struct BookList* tail);
