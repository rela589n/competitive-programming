#include <iostream>
#include "stack_container.cpp"

using namespace std;

int main() {
	stack_container<int> st;

	st.push(11);
	st.push(31);

	st.pop();
	st.top();
	
	st.push(341);
	
	st.pop();
	
	st.push(123);
	st.push(343);

	cout << st.size() << endl;
	cout << st.empty() << endl;

	st.clear();
	system("pause");
	return 0;
}