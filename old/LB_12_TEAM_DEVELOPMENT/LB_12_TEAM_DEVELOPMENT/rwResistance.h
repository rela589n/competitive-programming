#pragma once


bool readResistanceFromFile(string filename) {
	bool r = false;
	ifstream f(filename);

	string line;
	if (f.is_open()) {
		while ( getline(f, line) ) {
			cout << line << endl;
		}

		r = true;
	}
	f.close();
	return r;
}


bool writeResistanceIntoFile(string filename, double resistances[], int len, string additional) {
	bool r = false;
	char choise;

	cout << "Дозаписати (1) чи перезаписати (0) потрібно?\n";
	cin >> choise;


	int mode;
	if (choise == '0') {
		mode = ios::out;
	}
	else {
		mode = ios::app;
	}
	
	ofstream f(filename, mode);

	if (f.is_open()) {
		if (mode == ios::out) {
			f << "Команда unimpossible!\n\n\n";
		}
		else {
			f << endl;
		}
		outputResistanses(resistances, len, f);
		f << additional;
		f << endl;
		r = true;

	}
	f.close();
	return r;
}


