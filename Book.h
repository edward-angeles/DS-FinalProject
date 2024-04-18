#pragma once

#include <cstring>
#include "DateTime.h"

#pragma warning(disable:4996)

class Book {

private:
	char* title;
	char* author;
	char* genre;
	Date publicationDate;
	int availability;
	int totalReviews;
	float rating;

public:

	// constructor
	Book(char* title, char* author, char* genre, int day, int month, int year, int availability, int totalReviews = 0, float rating = 0) : publicationDate(day, month, year) {
		this->title = title;
		this->author = author;
		this->genre = genre;
		this->availability = availability;
		this->totalReviews = totalReviews;
		this->rating = rating;
	}

	Book(void) : publicationDate(DEFAULT_DAY, DEFAULT_MONTH, DEFAULT_YEAR){
		strcpy(title, "DEFAULT");
		strcpy(author, "DEFAULT1");
		strcpy(genre, "DEFAULT");
		availability = -100;
		totalReviews = 0;
		rating = 0;

	}


	char * GetTitle() const {
		return title;
	}

	char* GetAuthor() {
		return author;
	}

	char* GetGenre() {
		return genre;
	}

	int GetAvailability() {
		return availability;
	}

	int GetTotalReviews() {
		return totalReviews;
	}

	float GetRating() {
		return rating;
	}

	Date& GetPublicationDate() {
		return publicationDate;
	}



	
};