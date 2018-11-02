#include <iostream>
#include <ctime>

using namespace std;

int main() {
	unsigned long int t = clock(), i =1;
	while (i < 10000000) {
		i++;
		++i;
	}
	t = clock() - t;
	cout << t;
	system("pause");
	return 0;
}