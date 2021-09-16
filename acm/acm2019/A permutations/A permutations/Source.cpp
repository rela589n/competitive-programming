#include <iostream>
#include <set>
#include <list>
#include <vector>

using namespace std;
/*set<int> getNums(int n) {
	set<int> res;
	res.insert(n);

	for (int i = n - 1; i > 0; --i) {
		res.insert(i);
		res.insert(n + i);
	}

	return res;
}*/


set<int> getNums(int n) {
	set<int> res;

	for (int i = 1; i < 2 * n; ++i) {
		res.insert(i);
	}

	return res;
}


void printSet(set<int>& s) {
	for (int el : s) {
		cout << el << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	set<int> nums = getNums(n);
	//printSet(nums);

	vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
		//nums.erase(vec[i]);
	}

	list<int> res;
	res.push_back(vec[0]);
	nums.erase(vec[0]);
	
	for (int i = 1; i < n; ++i) {
		if (vec[i - 1] < vec[i]) {
			if (nums.find(vec[i]) != nums.end()) {
				res.push_back(vec[i]);
			}
			else {
				int end = *nums.rbegin();
				res.push_back(end);
				
				nums.erase(end);
			}

			int end = *nums.rbegin();
			res.push_back(end);

			nums.erase(end);
		}
		else if (vec[i - 1] > vec[i]) { // not sure
			if (nums.find(vec[i]) != nums.end()) {
				res.push_back(vec[i]);
			}
			else {
				auto begin = nums.begin();
				res.push_back(*begin);

				nums.erase(begin);
			}

			auto begin = nums.begin();
			res.push_back(*begin);

			nums.erase(begin);
		}
		else {
			int begin = *nums.begin();
			int end = *nums.rbegin();
			
			int el = *nums.find(vec[i]);
			if (vec[i] == begin) {

			}
			res.push_back(begin);
			res.push_back(end);

			nums.erase(begin);
			nums.erase(end);
		}
	}

	for (auto i = res.begin(); i != res.end(); ++i) {
		cout << *i << " ";
	}

	//system("pause");
	return 0;
}