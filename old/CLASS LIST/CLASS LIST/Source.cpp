#include <iostream>
#include "list.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	list<double> lst;

	lst.push_back(5);
	lst.push_back(7);
	lst.push_back(11);
	lst.push_back(101);
	lst.push_back(12);

	cout << (lst[2] = 123);



	lst.clear();

	lst.getSize();

	/*
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << endl;
	}
	
	cout << endl << "pop_back " << endl << endl;

	lst.pop_back();

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	*/

	system("pause");
	return 0;
}

