#include <iostream>

using namespace std;


int main() {

	int mydigits[200] = { 0 };
	int n;
	int perenos;

	cin >> n;

	mydigits[0] = 1; //digits=1;
	for (int f = 2; f <= n; f++)
	{ //digits=digits*f
		perenos = 0;
		for (int i = 0; i < 200; i++)
		{
			int temp;
			temp = mydigits[i] * f + perenos;
			mydigits[i] = temp % 10;
			perenos = temp / 10;
		}
	}
	
	for (int i = 199; i >= 0; i--)
		cout << mydigits[i];
	cout << endl;


	system("pause");
	return 0;
}