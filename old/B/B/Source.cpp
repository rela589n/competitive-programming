#include <iostream>
#include <string>

using namespace std;

void fromDecimalToBinary(int decimal, string &result) {
	if (decimal == 1) {
		result += "1";
		return;
	}

	fromDecimalToBinary(decimal >> 1, result);
	
	result += (decimal % 2) + '0';
}



int main()
{
	int n;
	cin >> n;

	
	string a = "";

	fromDecimalToBinary(n, a);

	int maxLen = 0;
	int len = 0;

	for (int i = 0; i < a.length(); ++i) {
		if (a[i] == '0') {
			++len;
		}
		else {
			if (len > maxLen) {
				maxLen = len;
			}
			len = 0;
		}
	}

	cout << maxLen << endl;

	system("pause");
	return 0;
}
