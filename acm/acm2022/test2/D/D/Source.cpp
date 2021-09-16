#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define INF 2147483646

using namespace std;

int n;
int r = 0, p = 1;

int main()
{
	cin >> n;

	while (p <= n) {
		p <<= 1;
		++r;
	}

	cout << r;

	return 0;
}

/*
1
2 3
4 5 6 7
8 9 10 11 12 13 14 15
16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31
*/