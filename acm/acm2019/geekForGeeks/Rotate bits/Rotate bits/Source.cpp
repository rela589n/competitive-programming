#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int maxBits = 16;

vector<bool> toBinary(int n) {
	vector<bool> res(maxBits, false);
	
	int counter = maxBits;
	while (n > 0) {
		res[--counter] = n % 2;
		n /= 2;
	}

	return res;
}

int toDecimal(vector<bool> bits) {
	int base = 1;
	int result = 0;

	for (int i = bits.size() - 1; i >= 0; --i) {
		result += bits[i] * base;
		base *= 2;
	}

	return result;
}

vector<bool> rotateRight(vector<bool> bits, int count) {
	vector<bool> res(bits.size());

	for (int i = 0; i < bits.size(); ++i) {
		int indx = (i - count) % maxBits;
		if (indx < 0) {
			indx = maxBits + indx;
		}
		res[i] = bits[indx];
	}
	
	return res;
}

vector<bool> rotateLeft(vector<bool> bits, int count) {
	vector<bool> res(bits.size());

	for (int i = 0; i < bits.size(); ++i) {
		res[i] = bits[(i + count) % maxBits];
	}

	return res;
}


int main() {

	int t, n, d;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		cin >> n >> d;
		
		cout << toDecimal(rotateLeft(toBinary(n), d)) << endl;
		cout << toDecimal(rotateRight(toBinary(n), d)) << endl;
	}

	//system("pause");
	return 0;
}