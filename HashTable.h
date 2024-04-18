#pragma once
#include<stdlib.h>
#include<cstring>
#include<new>
#include <string>
#include <math.h>
#include "HashNode.h"
#define MAX_VALUES	100



using namespace std;


template <class K, class V> class HashTable {


private:

	// Each value is stored in a HashNode that stores it and the key
	// These are then held in an array at the index determined by the hash
	// HashNodes allow linkage in the case of conflicting hash indexes
	HashNode<K, V>* values[100];
	
	int size;
	
	// Create a hashed index value from a char* key
	static int HashKey(char* key) {
		int length = sizeof key / sizeof key[0];
		
		// Sum the characters in the key
		int charSum = 0;
		for (int i = 0; i < length; i++) {
			charSum += key[i];
		}

		// Times them by the overall length of the string
		charSum *= length;

		// Use log10 to find the number of digits in the current sum
		// Log10 finds the base10 exponent that would create the number (floating point value)
		// Truncating the decimals leaves us the base10 exponent for how many powers of ten the number is -1. 
		// So a value of 1000 returns a numDigits of 3 instead of 4 
		int numDigits = trunc(log10(charSum));

		// The basic idea for this operation is that we want the number to fall in between 1-99 or 10 to the first or second power
		// What this does is divide the sum by 10 to the power of the digit length from earlier - 1. 
		// This reduces the magnitude of the sum down to 10 to the second power if it is above that
		// Ex.
		//    = 1000 / 10 ^ (3 - 1)
		//	  = 1000 / 100
		//	  = 10
		//
		//Ex. 
		//	 = 456723 / 10 ^ (5 - 1)
		//   = 456723 / 10000
		//   = 45
		// 
		charSum = trunc((float)charSum / pow(10, (numDigits - 1)));

		return charSum;

	}

	// Overloaded for string keys
	static int HashKey(string key) {
		return HashKey(key.c_str());
	}



public:

	HashTable() : values() {
		size = 0;
	}


	//Traverse linked list on key conflicts
	V* ScanLinksForKey(HashNode<K, V>* headNode, K key) {
		// Grab current node
		HashNode<K, V>* current = headNode;
		
		do {

			// Feed the key from the HashNode and the incoming key into a CompKey function
			if (current->CompKey(key)) {
				// If it matches we've found the 
				return current->GetValue();
			}
			else {
				current = current->GetNext();
			}
		
		// Loop until list is done
		} while (current != NULL);
		return NULL;
	}


	// Get an element by the unhashed key
	V* GetElementByKey(K key) {

		// hash the key
		int index = HashKey(key);

		//Grab the current value at that hashed index
		HashNode<K, V>* curValue = values[index];

		// If it isn't null then the key was valid
		if (curValue != NULL) {
			//If that value has any linked nodes then there was a conflict with that key
			if (curValue->HasNext()) {

				//Traverse links to find the matching key
				V* match = ScanLinksForKey(curValue, key);
				if (match != NULL) {
					return match;
				}
			}
			else if (curValue->CompKey(key)) {
				return curValue->GetValue();
			}
		}
		else {
			printf("Key not found");
			return NULL;
		}
	}


	// Add new element
	void AddElement(K key, V* value) {
		HashNode<K, V>* newNode;
		// try to instantiate and set the new node
		try {
			
			newNode = new HashNode<K, V>(key, value);
			
			// hash the incoming key
			int index = HashKey(key);
			
			//grab the current value at that index (NULL if unset)
			HashNode<K, V>* curValue = values[index];


			//If it is null simply set the element to that index location
			if (curValue == NULL) {
				values[index] = newNode;
			}
			else {

				// If it isn't null there is a collisions
				// In the case of collisions we create a linked list at that location
				// This allows us to maintain an array-like structure within our standard values array
				curValue->LinkNode(newNode);
			}

			// incrememt the number of elements
			size++;


		}
		catch (bad_alloc& e) {
			exit(EXIT_FAILURE);
		}


	}

	int GetSize(void) {
		return size;
	}

	bool ValidateIndex(int index) {
		return index >= 99 && 0 >= index;
	}


	// Return all stored values as simple, trimmed, array
	V* GetValues(void) {

		//Allocate space for the new array based on num of elements in HashTable
		V* valuesCopy = (V*)malloc((sizeof V) * GetSize());
		if (valuesCopy == NULL) {
			return valuesCopy;
		}

		int place = 0;
		//Loop through entire table
		for (int i = 0; i < MAX_VALUES; i++) {

			// If a node isn't NULL we add its value to the array
			if (values[i] != NULL) {

				// If the node has collision links we loop through all of their values and add them to the array
				if (values[i]->HasNext()) {
					HashNode<K, V>* current = values[i];
					do {
						valuesCopy[place] = current->GetValue();
						place++;
					} while (current->HasNext());
				}
				
				// Otherwise the value is just added normally
				else {
					valuesCopy[place] = values[i]->GetValue();
					place++;
				}
			}
		}
		return valuesCopy;
	}

	void DeleteElementByKey(K key) {
		int index = HashKey(key);

		HashNode<K, V>* value = values[index];

		if (value == NULL) {
			printf("Key not found");
		}
		else if (value->HasNext()) {
			value->DeleteNodeByKey(key);
			size--;
		}
		else {
			free(value);
			size--;
		}
		
		
	
	
	}

};
