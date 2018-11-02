#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	//пацюка, корови, тигра, зайця, дракона, змії, коня, вівці, мавпи, півня, собаки, свині. 
	// 1996 - пацюка
	long int n;
	char names[12][12] = {"мавпи", "півня", "собаки", "свині",  "пацюка", "корови", "тигра", "зайця", "дракона", "змії", "коня", "вівці"};
	cin >> n;
	cout << "Рік" << names[n % 12] << endl;
	system("pause");
	return 0;
}