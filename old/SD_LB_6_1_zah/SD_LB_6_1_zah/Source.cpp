#include <iostream>
#include <windows.h>
#include <cmath>
#include <ctime>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	long int k, x, quant_years = 0, bad_year = 0, bad_profit = 2000000000;
	float profit[50];
	cin >> k;
	cout << "year" << '\t' << "profit" << endl;
	for (x = 1993; x <= k; x++) {
		unsigned int indx = x - 1993;
		profit[indx]= rand() % 1501 - 500;
		cout << x << '\t' << profit[indx] <<endl;
		if (profit[indx] < 1000 && profit[indx] > 500) {
			quant_years++;
		}
		if (profit[indx] < bad_profit){
			bad_year = x;
			bad_profit = profit[indx];
		}
	}
	cout << "quantity years in what profit was > 500 and < 1000 ======> " << quant_years << endl;
	(bad_year) ? cout << "worst year: " << bad_year << endl : cout << "did not bad years"<< endl;
	system("pause");
	return 0;
}