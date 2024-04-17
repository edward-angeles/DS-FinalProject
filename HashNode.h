#pragma once



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

	V GetValue(void) {
		return *value;
	}

	K GetKey(void) {
		return key;
	}

	bool HasNext() {
		return next != NULL;
	}

	HashNode* GetNext() {
		return next;
	}

	void LinkNode(HashNode* node) {
		if (next == NULL) {
			next = node;
		}
		else {
			node->next = next;
			next = node;
		}
	}

};