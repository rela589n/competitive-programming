#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string findstem(vector<string>& arr)
{
	int n = arr.size();

	string s = arr[0];
	int len = s.length();

	string res = "";

	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j <= len; j++)
		{
			string stem = s.substr(i, j);
			int k = 1;
			for (k = 1; k < n; k++)
			{
				if (find(arr.begin(), arr.end(), stem) == arr.end())
					break;
			}

			// If current substring is present in 
			// all strings and its length is greater 
			// than current result 
			if (k == n && res.length() < stem.length())
				res = stem;
		}
	}

	return res;
}


int main() {
	int k;
	cin >> k;

	cin.get();
	vector<string> strings = vector<string>(k);

	for (int i = 0; i < k; ++i) {
		getline(cin, strings[i]);
	}

	cout << findstem(strings) << endl;

	system("pause");
	return 0;
}
/*
3
panchak
mrpak
drshak

*/