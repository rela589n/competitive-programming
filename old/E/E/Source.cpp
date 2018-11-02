#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];

	// number, amount in array
	map<int, int> dominances;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		++dominances[arr[i]];
	}

	int max, quantity = 0;
	for (auto elem : dominances) {
		if (elem.second > quantity) {
			max = elem.first;
			quantity = elem.second;
		}
	};

	if (quantity > n / 2) {
		cout << max;
	}
	else {
		cout << "No dominator";
	}

	//system("pause");
	return 0;
}