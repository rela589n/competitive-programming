#pragma once
#ifndef STRING_HASH_PROXY_DEFINITION
#define STRING_HASH_PROXY_DEFINITION

#include <string>
#include <vector>
#include <algorithm>

class HashPowers {
	static const unsigned long long P = 31ull;

public:
	static std::vector<unsigned long long>* powers;

	static unsigned long long at(const size_t& offset)
	{
		HashPowers::reserve(0u, offset);
		
		return HashPowers::powers->operator[](offset);
	}

	static void reserve(const size_t& from, const size_t& to)
	{
		if (HashPowers::powers->size() > to) return;

		HashPowers::powers->reserve(to * 2u);

		for (size_t i = std::max(from, powers->size()); i <= to; ++i) {
			HashPowers::powers->push_back((*powers)[i - 1] * HashPowers::P);
		}
	}

};

vector<unsigned long long>* HashPowers::powers = new vector<unsigned long long>({1ull});

class StringHashProxy
{
private:
	std::string* raw;

	/*
	  Hash stuff
	*/

	bool hashEnabled = false;
	std::vector<unsigned long long>* hashPrefixes;

	void enforceHashInit()
	{
		if (hashEnabled) return;

		hashEnabled = true;

		this->buildHashPrefixes();
	}

	void buildHashPrefixes()
	{
		this->hashPrefixes = new std::vector<unsigned long long>(this->size());

		(*this->hashPrefixes)[0u] = *this->raw->begin();
		for (size_t i = 1ull; i < this->hashPrefixes->size(); ++i) {
			(*this->hashPrefixes)[i] = this->hashPrefixUncheckedAt(i - 1u) + HashPowers::at(i) * this->at(i);
		}
	}

	unsigned long long hashPrefixAt(const size_t& at)
	{
		this->enforceHashInit();

		return this->hashPrefixUncheckedAt(at);
	}

	unsigned long long hashPrefixUncheckedAt(const size_t& at)
	{
		return (*this->hashPrefixes)[at];
	}

	unsigned long long getPreHash(const size_t& left, const size_t& right) {
		long long result = this->hashPrefixAt(right);

		if (left > 0) {
			result -= this->hashPrefixAt(left - 1u);
		}

		return result;
	}

public:

	StringHashProxy(std::string* raw)
	{
		this->raw = raw;
	}

	char at(const size_t& offset)
	{
		return this->raw->operator[](offset);
	}

	void set(const size_t& at, char value)
	{
		this->raw->operator[](at) = value;
	}

	size_t size()
	{
		return this->raw->length();
	}

	bool slicesEqual(const size_t& left1, const size_t& right1, const size_t& left2, const size_t& right2)
	{
		return this->getPreHash(left1, right1) * HashPowers::at(left2)
			== this->getPreHash(left2, right2) * HashPowers::at(left1);
	}

	bool sliceEqualWithOther(const size_t& left, const size_t& right, StringHashProxy* other, const size_t& other_left, const size_t& other_right)
	{
		return this->getPreHash(left, right) * HashPowers::at(other_left)
			== other->getPreHash(other_left, other_right) * HashPowers::at(left);
	}
};


#endif // !STRING_HASH_PROXY_DEFINITION

