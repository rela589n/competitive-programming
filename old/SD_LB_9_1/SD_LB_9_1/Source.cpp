#include <iostream>
#include <iomanip>

using namespace std;

struct ECM {
	char CPU_type[50];
	unsigned int  HDD, year;
	float CPU_frequency_Ghz, cost, RAM;
};

void form(ECM a[], int len);
void output(ECM a[], int len);
void ECM_indx_max(ECM a[], int len, ECM max_indexes[], int &indx_len);
void scrollDown(int);

int main() {
	int n;
	ECM computers[100];

	cout << "Enter number of computers: ";
	cin >> n;
	form(computers, n);
	output(computers, n);

	system("pause");
	scrollDown(5);

	int index_len;
	ECM *max_indexes = new ECM[n];
	ECM_indx_max(computers, n, max_indexes, index_len);

	cout << "Info about computers with latest year of issue:\n\n";
	output(max_indexes, index_len);

	/*
	output(computers, n);
	

	INTEL CORE i3-5010U		3.7     8       1000    2016    12000
	INTEL CORE i7-7700H		5       16      1000    2018    18000
	INTEL CORE i9-8950HK	4.8     32      2000    2018    50000
		*/
	system("pause");
	return 0;
}


void form(ECM a[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "\t\t\tEnter for " << i + 1 << " ECM:\n";
		cout << "CPU type: ";
		cin.get();
		gets_s(a[i].CPU_type);
		cout << "CPU frequency in Ghz: ";
		cin >> a[i].CPU_frequency_Ghz;
		cout << "Amount of RAM in GB: ";
		cin >> a[i].RAM;
		cout << "HDD capacity in GB: ";
		cin >> a[i].HDD;
		cout << "Year of issue: ";
		cin >> a[i].year;
		cout << "Cost of ECM: ";
		cin >> a[i].cost;
	}
}

void output(ECM a[], int len) {
	cout << setw(14) << "CPU type";
	cout << setw(23) << "CPU frequency in Ghz";
	cout << setw(23) << "Amount of RAM in GB";
	cout << setw(22) << "HDD capacity in GB";
	cout << setw(19) << "Year of issue";
	cout << setw(19) << "Cost of ECM\n\n";
	for (int i = 0; i < len; i++) {
		cout << setw(14) << a[i].CPU_type;
		cout << setw(23) << a[i].CPU_frequency_Ghz;
		cout << setw(23) << a[i].RAM;
		cout << setw(22) << a[i].HDD;
		cout << setw(19) << a[i].year;
		cout << setw(18) << a[i].cost << endl;
	}
	cout << endl;
}

void ECM_indx_max(ECM a[], int len, ECM max_years[], int &indx_len) {
	int max = a[0].year;
	max_years[0] = a[0];
	indx_len = 1;
	for (int i = 1; i < len; i++) {
		if (a[i].year > max) {
			max = a[i].year;
			indx_len = 1;
			max_years[0] = a[i];
		}
		else if (max == a[i].year) {
			max_years[indx_len++] = a[i];
		}
	}
}


void scrollDown(int n) {
	for (int i = 0; i <= n; i++)
		cout << endl;
}
