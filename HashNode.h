#pragma once

#include <stdlib.h>
#include <string.h>
#include "Book.h"
using namespace std;
// HashNodes store key,value pairs and become a linear linked list in the event of a collision
template <class K, class V> class HashNode {
private:
	V* value;
	K key;
	HashNode* next;

public:
	HashNode(K k, V *v) : next() {
		key = k;
		value = v;
	}

	HashNode(void) : next() {
		key = NULL;
		value = NULL;
	}

	// Compares two char* keys to see if they are equivalent
	bool CompKey(char* key) {
		return strcmp(this->key, key) == 0;
	}


	//Overloaded for string keys
	bool CompKey(string value) {
		return CompKey(key, (char*)value.c_str());
	}

	


	V* GetValue(void) {
		return value;
	}


	void SetValue(V* value) {
		this->value = value;
	}



	K GetKey(void) {
		return key;
	}



	void SetKey(K key) {
		strcpy(this->key, key);
	}


	void operator=(const HashNode& RHS) {
		key = RHS.key;
		value = RHS.value;
		next = RHS.next;
	}

	bool HasNext() {
		return next != NULL;
	}


	HashNode<K, V>* GetNext() {
		return next;
	}


	void SetNext(HashNode* next) {
		this->next = next;
	}

	void DeleteNodeByKey(K key) {
		HashNode<K, V>* current = this;
		HashNode<K, V>* previous = NULL;
		
		do {
			if (current->CompKey(key)) {
				if (previous == NULL) {
					if (current->GetNext() == NULL) {
						free(this);
						break;
					}
					else {
						*this = *this->next;
						this->next = NULL;
						break;
					}
				}
				else {
					previous->next = current->next;
					free(current);
					break;
				}
			}
			else {
				previous = current;
				current = current->next;
			}
		} while (current != NULL);

	}

	void LinkNode(HashNode* node) {
		if (this->next == NULL) {
			this->next = node;
		}
		else {
			node->next = this->next;
			this->next = node;
		};
	}

};
