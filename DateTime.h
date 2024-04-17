#pragma once

#include <stdio.h>
#define MAX_YEAR		2100
#define DEFAULT_YEAR	1947
#define DEFAULT_MONTH	12
#define DEFAULT_DAY		23
#define NUM_MONTHS		12


class Date {

private:
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day;
	int month;
	int year;

public:
	Date(int day, int month, int year) : daysInMonth() {
		
		// If the month isn't in range we can't check to see if the day is in range for that month so we default both
		if (month > 12 || month <= 0) {
			this->day = DEFAULT_DAY;
			this->month = DEFAULT_MONTH;
		}

		// Check to see if the day is valid for that month and is greater than zero
		else if (day > daysInMonth[month - 1] || day <= 0) {

			// Handling Leap Years
			// Check to see if the month input is February
			if (month == 2) {
				// Check to see if it is a leap year
				if (year % 400 == 0) {
					// Check to see if the day input is 29
					if (day == 29) {
						// Set the day data member to the input if it meets all conditions
						this->day = day;
					}
					else {
						this->day = DEFAULT_DAY;
					}
				}
				else {
					this->day = DEFAULT_DAY;
				}
			}
			else {
				this->day = DEFAULT_DAY;
			}
			this->month = month;
		}
		else {
			this->day = day;
			this->month = month;
		}


		if (year <= MAX_YEAR) {
			this->year = year;
		}
		else {
			this->year = DEFAULT_YEAR;
		}
	};


	int GetDay(void) {
		return this->day;
	}

	int GetMonth(void) {
		return this->month;
	}

	int GetYear(void) {
		return this->year;
	}

	void PrintDate(void) {
		printf("%d/%d/%d\n", GetDay(), GetMonth(), GetYear());
	}
	
};