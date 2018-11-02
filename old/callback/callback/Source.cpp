#include <iostream>
#include <ctime>

void print_hello();
int* mmax(int& m, int& n, void(*callback)());

using namespace std;

bool compare(int a, int b) {
	return a > b;
}

// default param
void construct(int a, int b, bool (*_compare)(int a, int b) = compare) {
	if (_compare(a, b)) {
		cout << "a > b";
	}
	else {
		cout << "a !> b";
	}
}



int main() {
	construct(4, 3);
	
	cin.get();
	
	srand(time(NULL));


	int a = 3, b = 10;
	int* (*p)(int& m, int& n, void(*callback)());
	p = mmax;
	cout << *p(a, b, print_hello);


	system("pause");
	return 0;
}

int* mmax(int& m, int& n, void(*callback)()) {
	if (m > n) {
		return &m;
	}
	callback();
	return &n;
}

void print_hello() {
	cout << "hello, world";
}