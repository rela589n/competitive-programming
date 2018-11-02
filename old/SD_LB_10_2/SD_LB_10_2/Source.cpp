#include <iostream>
#include <fstream>

using namespace std;

double formula(double param, char path[], double eps = 0.00000001);
void readFromFile(char path[]);

int main() 
{
	double x;
	char choise;

	start:
	cout << "1 - read from file" << endl << "2 - write into file" << endl;
	cin >> choise;

	char path[] = "rezult.txt";
	switch (choise)
	{
	case '1':{
		readFromFile(path);
		break;
	}
	case '2':{
		cout << "enter a number for the formula: ";
		cin >> x;
		cout << formula(x, path);
		break;
	}
	default:
		cout << "error! wrong input!\n repeat input.\n";
		goto start;
		break;
	}

	cout << endl;
	system("pause");
	return 0;
}


double formula(double param, char path[], double eps) {
	ofstream f(path);
	double a = 1, s = 1;
	unsigned int n = 0;

	f << "Elements of row:\n";
	f.setf(ios::fixed);
	f.precision(14);
	f << "a[" << n << "]\t= " << a << endl;
	do {
		a *= param * (n + 1 + 1. / (n + 1)) / 2. / (n*n + 1.);
		f << "a[" << ++n << "]\t= " << a << endl;
		s += a;
	} while (fabs(a) > eps);
	f << "Summ of row: " << s;
	f.close();
	return s;
}

void readFromFile(char path[]) {
	ifstream f(path);
	if (!f.is_open()) {
		cout << "file is not exists!";
		return;
	}
	while (!f.eof()) {
		char line[400];
		f.getline(line, 400);
		cout << line << endl;
	}
	f.close();
}

