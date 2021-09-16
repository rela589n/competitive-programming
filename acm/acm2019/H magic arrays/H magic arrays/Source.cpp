#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

void production();
void developement();

class Solve
{
public:

	map<int, int> arr;

	int n;
	Solve(map<int, int>& arr)
	{
		this->arr = arr;
		this->n = arr.size();
	}

	list<int> solve()
	{
		list<list<int>> parts;
		list<int> tmp;
		while ((tmp = nextSplit()).size() > 0) {
			parts.push_back(tmp);
		}
		return mergeSolutions(parts);
	}

	list<int>& nextSplit()
	{
		list<int>* ans = new list<int>();
		
		for (auto i = arr.begin(); i != arr.end(); ++i) {
			if (i->second > 0) {
				ans->push_back(i->first);
				--i->second;
			}
		}
		
		return *ans;
	}

	list<int> mergeSolutions(list<list<int>> parts)
	{
		list<int> tmp = *parts.begin();
		
		for (auto lst = ++parts.begin(); lst != parts.end(); ++lst) {
			if (!mergeTwo(tmp, *lst)) {
				return list<int>();
			}
		}

		if (!isMagic(tmp)) {
			return list<int>();
		}
		
		return tmp;
	}

	// merge & save into part1
	bool mergeTwo(list<int>& part1, list<int>& part2) { // lists are ascending sorted
		int l1 = *part1.begin();
		int r1 = *part1.rbegin();

		int l2 = *part2.begin();
		int r2 = *part2.rbegin();

		if (abs(r1 - r2) <= 1) {
			part2.reverse();
			part1.splice(part1.end(), part2);
		}
		else if (abs(r1 - l2) <= 1) {
			part1.splice(part1.end(), part2);
		}
		else if (abs(l1 - r2) <= 1) {
			part2.splice(part2.end(), part1);
			part1 = part2;
		}
		else if (abs(l1 - l2) <= 1) {
			part2.reverse();
			part2.splice(part2.end(), part1);
			part1 = part2;
		}
		else {
			return false;
		}
		
		return true;
	}

	static bool isMagic(list<int>& lst) {
		if (lst.size() == 0) {
			return false;
		}
		
		int prev = *lst.begin();
		int current = prev;
		bool ascending = prev == 0;

		for (auto i = ++lst.begin(); i != lst.end(); ++i, prev = current) {
			current = *i;
			if (current == 0) {
				if (prev != 0 && prev != 1) {
					return false;
				}

				ascending = true;
			}
			else {
				if (ascending) {
					if (prev - current == 0 || current - prev == -1) {
						ascending = false;
					}
					else if (current - prev != 1) {
						return false;
					}
				}
				else if (prev - current != 1) {
					return false;
				}
			}
			prev = current;
		}

		return ascending;
	}
};

bool dev = true;

int main() {
	if (dev) {
		developement();
	}
	else {
		production();
	}

	return 0;
}

void production() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		map<int, int> elemsCount;
		for (int j = 0; j < n; ++j) {
			int el;
			cin >> el;
			++elemsCount[el];
		}

		Solve s(elemsCount);
		
		list<int> result = s.solve();
		if (result.size()) {
			cout << "Yes" << endl;
			for (auto el : result) {
				cout << el << " ";
			}
			cout << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}

void developement() {
	vector<list<int>> tests = {
		{ 0, 0, 1, 1, 2, 2 },
		{ 0, 0, 1, 1, 2 },
		{ 2, 2, 1, 0, 0, 1, 2, 3, 2, 1, 0, 1, 2, 3, 2, 1, 0, 1, 2, 3 },
		{ 1, 2, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 1, 1, 1, 2, 2, 3, 3}
	};

	for (auto lst : tests) {
		map<int, int> elemsCount;
		for (auto el : lst) {
			++elemsCount[el];
		}
		Solve s(elemsCount);
		list<int> result = s.solve();
		
		if (result.size()) {
			cout << "Yes" << endl;
			for (auto el : result) {
				cout << el << " ";
			}
			cout << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	system("pause");
}
/*
6
0 0 1 1 2 2 => true

5
0 0 1 1 2 => true



*/