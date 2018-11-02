#include <iostream>
#include "set_container.cpp"
#include <set>

using namespace std;

int main() {	
	
	set_container<int> s;

	s.insert(2);
	s.insert(3);
	s.insert(7);
	s.insert(5);
	s.insert(6);
	s.insert(4);
	s.insert(18);
	s.insert(10);
	s.insert(16);
	
	s.insert(20);
	s.insert(22);
	s.insert(22);
	s.insert(9);
	s.insert(8);
	s.insert(10);

	
	s.eachReverse([](const int& i) {
		cout << i << endl;
	});
	
	cout << endl;

	cout << s.findLeast()[0];
	
	system("pause");
	return 0;
}