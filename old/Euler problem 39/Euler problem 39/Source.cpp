#include <iostream>

using namespace std;

int number_of_answers(int p) {
	int ans = 0;

	for (int a = 1; a < p / 3; ++a) {
		for (int b = a; b < p / 2; ++b) {
			int c = p - a - b;

			if (a * a + b * b == c * c) {
				++ans;
			}
		}
	}

	return ans;
}



int main() {
	int p;
	cin >> p;

	int max_p = 0;
	int max = 0;

	for (int i = 1; i <= p; ++i) {
		int current = number_of_answers(i);
		
		if (max < current) {
			max = current;
			max_p = i;
		}
	}
	
	cout << max << endl;
	cout << max_p << endl;

	cin.get();
	cin.get();
	cin.get();
	return 0;
}