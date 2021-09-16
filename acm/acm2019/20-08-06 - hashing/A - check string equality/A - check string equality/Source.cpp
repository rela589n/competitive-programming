#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

#define ull unsigned long long
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


int main()
{
	//ios_base::sync_with_stdio(0);

	char str[(st)1e5];
	cin >> str;

	st n = strlen(str);

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

	size_t t;
	cin >> t;
	for (size_t i = 0u; i < t; ++i) {
		size_t l, r, f, s;

		scanf("%d %d %d %d", &l, &r, &f, &s);

		--l;
		--r;
		--f;
		--s;

		if (slicesEqual(l, r, f, s)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	//system("pause");
	return 0;
}
/*
abcabc
3
1 3 4 6
1 2 5 6
2 3 5 6
*/