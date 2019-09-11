#pragma once

typedef long long Int;

class HashMap {
private:
	class HashEntry;
	HashEntry** table;
	int TABLE_SIZE;

	class HashEntry {
	private:
		int key;
		Int value;
	public:
		HashEntry(int key, Int value) {
			this->key = key;
			this->value = value;
		}

		int getKey() {
			return key;
		}

		Int& getValue() {
			return value;
		}
	};

public:
	HashMap(int tableSize = 128) {
		this->TABLE_SIZE = tableSize;
		table = new HashEntry * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = nullptr;
	}

	Int& operator [] (int key) {
		int hash = (key % TABLE_SIZE);
		while (table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] == nullptr)
			table[hash] = new HashEntry(key, Int());
		
		return table[hash]->getValue();
	}

	void put(int key, Int value) {
		int hash = (key % TABLE_SIZE);
		while (table[hash] != nullptr && table[hash]->getKey() != key)
			hash = (hash + 1) % TABLE_SIZE;
		if (table[hash] != nullptr)
			delete table[hash];
		table[hash] = new HashEntry(key, value);
	}

	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; i++)
			if (table[i] != nullptr)
				delete table[i];
		delete[] table;
	}
};