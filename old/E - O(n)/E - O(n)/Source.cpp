#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int findEl(int elements[], int len, int elem) {
	int l = 0,
		r = len - 1;
	
	int cen;
	while (l < r) {
		cen = (l + r) / 2;

		if (elem < elements[cen]) {
			r = cen - 1;
		}
		else if (elem > elements[cen]) {
			l = cen + 1;
		}
		else {
			l = r = cen;
		}
	}

	if (elements[l] == elem)
		return l;
		
	return -1;
}

int main() {
	srand(time(NULL));

	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int testElements[7];

	for (int i = 0; i < 7; ++i) {
		testElements[i] = arr[rand() % n];
	}

	sort(testElements, testElements + 7);
	int quantities[7] = { 0 };

	int curr;
	for (int i = 0; i < n; ++i){
		curr = arr[i];

		int founded = findEl(testElements, 7, curr);
		if (~founded) {
			++quantities[founded];
		}
	}

	int quantMax = quantities[0],
		maxElem = testElements[0];
	
	for (int i = 1; i < 7; ++i) 
	{
		if (quantMax < quantities[i]) 
		{
			quantMax = quantities[i];
			maxElem = testElements[i];
		}
	}

	if (quantMax > n / 2) {
		cout << maxElem;
	}
	else {
		cout << "No dominator";
	}


	



	
	//system("pause");
	return 0;
}

