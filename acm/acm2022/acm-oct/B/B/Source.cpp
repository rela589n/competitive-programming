#include<bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

int n;
vector<bool> ar = vector<bool>(10000, 0);


int main() {
	/*ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
*/
	cin >> n;

	int first = 0;
	int second = 0;

	int dist = -1;

	for (int i = 0; i < n - 2; ++i) {
		cout << "? " << i << " " << n - 2 << " " << n - 1 << endl;
		fflush(stdout);

		int b;
		cin >> b;
		ar[i] = b;

		if (i == 0) {
			continue;
		}

		if (ar[i] == ar[first]) {
			second = i;
		}
		else {
			dist = i;
		}
	}


	if (first == second) {
		++first;
		second = first + 1;
	}

	int b;

	cout << "? " << n - 2 << " " << first << " " << n - 1 << endl;
	fflush(stdout);

	cin >> b;

	if (b == ar[first]) {
		ar[n - 2] = ar[first];
	}
	else {
		ar[n - 2] = !ar[first];
	}

	cout << "? " << n - 1 << " " << first << " " << second << endl;
	fflush(stdout);

	cin >> b;

	bool oneIsProg;

	if (b == ar[first]) {
		ar[n - 1] = !ar[first];
		oneIsProg = !true;
	}
	else {
		ar[n - 1] = ar[first];
		oneIsProg = !false;
	}

	cout << "! ";

	for (int i = 0; i < n; ++i) {
		cout << (int)ar[i];
	}

	cout << endl;


	return 0;
}