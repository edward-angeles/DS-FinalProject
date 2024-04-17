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
		int size = sizeof key / sizeof key[0];
		
		// Sum the characters in the key
		int charSum = 0;
		for (int i = 0; i < size; i++) {
			charSum += key[i];
		}

		// Times them by the overall length of the string
		charSum *= size;

		// Use log10 to find the number of digits in the current sum
		// Divide the sum by ten raised to the power of that number minus 1 to always reduce the sum to a 1 - 2 digit number
		// Truncate the result to remove decimals
		// This produces a number between 1-99 
		// Can be modified to produce a wider range  
		charSum = trunc(charSum / pow(10, (trunc(log10(charSum) - 1))));

		return charSum;

	}

	// Overloaded for string keys
	static int HashKey(string key) {
		return HashKey(key.c_str());
	}


	// Compares two char* keys to see if they are equivalent
	static bool CompKey(char* value1, char* value2) {
		return strcmp(value1, value2) == 0;
	}


	// Overloaded for string keys
	static bool CompKey(string value1, string value2) {
		return CompKey(value1.c_str(), value2.c_str());
	}


public:

	HashTable() : values() {
		size = 0;
	}


	//Traverse linked list on key conflicts
	V ScanLinksForKey(HashNode<K, V>* headNode, K key) {
		// Grab current node
		HashNode<K, V>* current = headNode;
		
		do {

			// Feed the key from the HashNode and the incoming key into a CompKey function
			if (CompKey(current->GetKey(), key)) {
				// If it matches we've found the 
				return current->GetValue();
			}
		
		// Loop until list is done
		} while (current->HasNext());
	}


// Get an element by the unhashed key
V GetElementByKey(K key) {

	// hash the key
	int index = HashKey(key);

	//Grab the current value at that hashed index
	HashNode<K, V>* curValue = values[index];

	// If it isn't null the key was valid
	if (curValue != NULL) {
		//If that value has any linked nodes then there was a conflict with that key
		if (curValue->HasNext()) {

			//Traverse links to find the matching key
			return ScanLinksForKey(curValue, key);
		}
		else {
			//Otherwise return value
			return curValue->GetValue();
		}
	}
	return NULL;
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

				// If it isn't null there is a conflict
				// In the case of conflicts we create a linked list at that location
				// This allows us to maintain an array-like structure within our standard values array
				curValue->LinkNode(newNode);
			}

			// incrememt the number of elements
			size++;


		}
		catch (bad_alloc& e) {
			return;
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

	
};
