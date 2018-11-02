#pragma once

double resistance_successively(double resistances[], int l);
double resistance_parallel(double resistances[], int l);
double summary_resistance_successively(double r1, double r2, double r3);
double summary_resistance_parallel(double r1, double r2, double r3);


// 1
double resistance_successively(double resistances[], int l) {
	double r = 0;
	for (int i = 0; i < l; i++) {
		if (resistances[i] >= 0) {
			r = r + resistances[i];
		}
		else {
			r = -1;
			break;
		}
	}
	return r;
}

//2
double resistance_parallel(double resistances[], int l) {
	double numer = 1, denom = 0, r;

	for (int i = 0; i < l; i++) {
		if (resistances[i] >= 0) {
			numer = numer * resistances[i];
			denom = denom + resistances[i];
		}
		else {
			denom = 0;
			break;
		}
	}

	if (denom == 0) {
		r = -1; 
	}
	else {
		r = numer / denom;
	}

	return r;
}

//3
double summary_resistance_successively(double r1, double r2, double r3) {
	double r;
	if (r1 < 0 || r2 < 0 || r3 < 0) {
		r = -1; 
	}
	else{
		r = (r1*r2 + r2 * r3 + r3 * r1) / (r1 + r2);
	}
	return r;
}

//4
double summary_resistance_parallel(double r1, double r2, double r3) {
	double r;
	if (r1 < 0 || r2 < 0 || r3 < 0) { 
		r = -1; 
	}
	else {
		r = (r1*r3 + r2 * r3) / (r1 + r2 + r3);
	}
	return r;
}