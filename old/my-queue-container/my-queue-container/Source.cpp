#include <iostream>
#include "queue_container.cpp"

using namespace std;

int main() {
	queue_container<int> q;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	
	cout << q.back() << endl;
	cout << q.back() << endl;
	
	q.pop();

	cout << q.back() << endl;

	cout << q.size() << endl;
	cout << q.empty() << endl;

	q.pop();

	cout << q.back() << endl;

	q.clear();

	cout << q.empty() << endl;
	cout << q.size() << endl;


	system("pause");
	return 0;
}
