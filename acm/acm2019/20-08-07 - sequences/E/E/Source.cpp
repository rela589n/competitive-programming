#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ull unsigned long long
#define ll long long
#define Int long long
#define st size_t

ull P = 27;

ull* powers;
ull* prefixes;

inline ull getPreHash(const st& left, const st& right) {
	ull result = prefixes[right];

	if (left > 0) {
		result -= prefixes[left - 1u];
	}

	return result;
}

inline bool slicesEqual(const size_t& left1, const size_t& right1, const size_t& left2, const size_t& right2) {
	return getPreHash(left1, right1) * powers[left2]
		== getPreHash(left2, right2) * powers[left1];
}

ll n;
string str;

vector<bool> dividers(Int to)
{
	vector<bool> dividers(to + 1, true);

	dividers[0] = false;
		dividers[1] = true;

	for (Int i = 2; i * i <= to; ++i)
	{
		if (to % i == 0) {
			dividers[i] = true;
		}
	}

	return dividers;
}

bool str_replace(std::string& str, const std::string& from, const std::string& to) { // replace $"from" into $"to" in $"str"
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

int main() {
	cin.tie(NULL);
	getline(cin, str);

	n = str.length();

	powers = new ull[n];
	powers[0] = 1;
	for (st i = 1; i < n; ++i) {
		powers[i] = powers[i - 1] * P;
	}

	prefixes = new ull[n];
	prefixes[0] = str[0];
	for (st i = 1; i < n; ++i) {
		prefixes[i] = prefixes[i - 1] + powers[i] * str[i];
	}

	vector<bool> isPrime = dividers(n);

	int sequenceLen = n;

	for (int len = 1; len < isPrime.size(); ++len) 
	{
		if (isPrime[len] && n % len == 0) 
		{
			bool found = true;

			for (int j = 0; j < n - len; j += len) {

				if (!slicesEqual(j, j + len - 1, j + len, j + len + len - 1)) {
					found = false;
					break;
				}
			}

			if (found) {
				sequenceLen = len;
				break;
			}
		}
	}
	if (sequenceLen < n) {
		str.replace(sequenceLen, n, "");
	}
	
	cout << str << "\n";

	//system("pause");
	return 0;
}

/*

asdfasdfasdf

abab

2

0 1 2 3

*/