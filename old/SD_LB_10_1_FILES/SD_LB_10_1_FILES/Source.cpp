#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
void readFromFile(char path[]);
void writeInFile(char path[], int mode, double start, double end, double step, bool displayOnScreen = true);

int main() 
{
	double start, end, step;
	unsigned int mode;
	char choise;
	bool flg = true;

	start:
	cout << "what you want to do?\n";
	cout << "a - append into file\nb - write into file\nc - read form file\n";
	cin >> choise;
	switch (choise) {
	case 'a':
		mode = ios::app;
		break;
	case 'b':
		mode = ios::out;
		break;
	case 'c':{
		char path[] = "f1.doc";
		flg = false;
		readFromFile(path);
		break;
	}
	default:
		cout << "Input error! Please repeat input.\n";
		goto start;
	}
	if(flg){
		cout << "enter start point for x: ";
		cin >> start;
		cout << "\nenter end point for x: ";
		cin >> end;
		cout << "\nenter step for x: ";
		cin >> step;

		char path[10] = "f1.doc";
		writeInFile(path, mode, start, end, step);
		strcpy_s(path, "f2.xls");
		writeInFile(path, mode, start, end, step, false);
	}
	system("pause");
	return 0;
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

void writeInFile(char path[], int mode, double start, double end, double step, bool displayOnScreen) {
	double y;
	int quantityLess0 = 0, quantityMore0 = 0;
	ofstream f(path, mode);

	if (displayOnScreen) {
		cout.setf(ios::fixed);
		cout.precision(4);
		cout << setw(10) << "\n\n\tx" << "\t" << setw(15) << "y" << endl;
	}

	f << setw(10) << "\n\n\tx" << "\t" << setw(15) << "y" << endl;

	f.setf(ios::fixed);
	f.precision(4);

	for (double x = start; x <= end + step / 8.; x += step) {
		y = 3 - x - 4 / ((x + 2)*(x + 2));
		if (displayOnScreen) {
			cout << setw(10) << x << "\t" << setw(15) << y << endl;
		}
		f << setw(10) << x << "\t" << setw(15) << y << endl;
		if (y < 0)
		{
			quantityLess0++;
		}
		else if (y)
		{
			quantityMore0++;
		}
	}
	if (displayOnScreen) {
		cout << "\nquantity of f(x) that > 0: " << quantityMore0 << endl;
		cout << "quantity of f(x) that < 0: " << quantityLess0 << endl;
	}
	
	f << "\nquantity of f(x) that > 0: " << quantityMore0 << endl;
	f << "quantity of f(x) that < 0: " << quantityLess0 << endl;
	
	f.close();
}
