#include <iostream>
#include <string>

using namespace std;

bool isg[26] = {};
int costs[26] = {};


bool isG(char sym) {
	return isg[sym - 'a'];
}

int costS(char sym) {
	return costs[sym - 'a'];
}

int main() {
	isg['a' - 'a'] = true;
	isg['o' - 'a'] = true;
	isg['u' - 'a'] = true;
	isg['i' - 'a'] = true;
	isg['e' - 'a'] = true;

	int n;
	cin >> n;

	for (int i = 0; i < 26; ++i) {
		cin >> costs[i];
	}

	cin.get();

	for (int i = 0; i < n; ++i) {
		string str;
		getline(cin, str);

		char* result = new char[str.length()];
		int resultLen = 0;

		for (int j = 0; j < str.length(); ++j) {
			if (isG(str[j])) {
				result[resultLen++] = str[j];
			}
			else {
				
				int maxCost = costS(str[j]);
				int maxSym = str[j];

				int k = j + 1;
				for (; k < str.length(); ++k) {
					if (isG(str[k])) {
						break;
					}

					int currCos = costS(str[k]);
					if (maxCost < currCos || (maxCost - currCos == 0 && maxSym > str[k])) {
						maxCost = currCos;
						maxSym = str[k];
					}
				}

				result[resultLen++] = maxSym;

				j = k - 1;
			}
		}

		for (int _asdf = 0; _asdf < resultLen; ++_asdf) {
			cout << result[_asdf];
		}
		cout << endl;
		delete[] result;

	}



	//system("pause");
	return 0;
}
/*
3
0 0 0 0 0 0 1 0 0 0 0 0 0 0 5 0 4 0 0 0 2 3 4 0 0 0
magdich
ighor
anglishska

*/