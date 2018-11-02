#include <iostream>
#include <vector>

using namespace std;

struct structTree {
	double pos;
	double height;
};

double lineFunction(double x, double x0, double y0, double x1, double y1) {
	return (x - x0) / (x1 - x0) * (y1 - y0) + y0;
}

int main() {
	int n;
	cin >> n;

	vector<structTree> trees(n);

	for (int i = 0; i < n; ++i) {
		cin >> trees[i].pos >> trees[i].height;
	}

	structTree lighter;
	cin >> lighter.pos >> lighter.height;

	long double cut = 0;

	for (int i = 1; i < n && lighter.pos > trees[i].pos; ++i) 
	{
		double heightOfDotOnLine = lineFunction(trees[i].pos, trees[i - 1].pos, trees[i - 1].height, lighter.pos, lighter.height);

		if (trees[i].height > heightOfDotOnLine) {
			cut += trees[i].height - heightOfDotOnLine;
			trees[i].height -= trees[i].height - heightOfDotOnLine;
		}

	}


	for (int i = n - 2; i >= 0 && lighter.pos < trees[i].pos; --i)
	{
		double heightOfDotOnLine = lineFunction(trees[i].pos, trees[i + 1].pos, trees[i + 1].height, lighter.pos, lighter.height);

		if (trees[i].height > heightOfDotOnLine) {
			cut += trees[i].height - heightOfDotOnLine;
			trees[i].height -= trees[i].height - heightOfDotOnLine;
		}

	}

	cout.setf(ios::fixed);
	cout.precision(13);
	
	cout << cut;

	//system("pause");
	return 0;
}