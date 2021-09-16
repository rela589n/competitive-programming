#include <iostream>
#include <vector>

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

	int l, r;
	cin >> l >> r;

	vector<bool> lBin = toBinary(l);
	vector<bool> rBin = toBinary(r);

	vector<bool> resBin(maxBits, false);
	int i;
	for (i = 0; i < maxBits && lBin[i] == rBin[i]; ++i);

	for (int j = i; j < maxBits; ++j) {
		resBin[j] = true;
	}

	cout << toDecimal(resBin);

	//system("pause");
	return 0;
}