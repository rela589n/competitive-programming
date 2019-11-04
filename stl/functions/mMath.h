#pragma once

const double FUNC_EPS = 0.0000000000001;
const double MATH_PI = 3.1415926535897932384626;

double mycos(double number, double eps = FUNC_EPS);
double mysin(double number, double eps = FUNC_EPS);
double mytg(double number, double eps = FUNC_EPS);
double myctg(double number, double eps = FUNC_EPS);
double mylog(double num, double eps = FUNC_EPS);
double myexp(double num, double eps = FUNC_EPS);
double mypow(double num, double power);
double mypow(double num, int power);
double mfabs(double num);

double mycos(double number, double eps) {
	double a, x = number, s, n = 1, PI = MATH_PI;
	if (x >= 2 * PI)
		x -= 2 * PI * (long int)(x / (2 * PI));
	a = s = 1;
	do {
		a *= -x * x / (n*(n + 1));
		s += a;
		n += 2;
	} while (mfabs(a) > eps);
	return s;
}

double mysin(double number, double eps) {
	double a, x = number, s, n = 2, PI = MATH_PI;

	if (x >= 2 * PI)
		x -= 2 * PI * (long int)(x / (2 * PI));
	a = s = x;
	do {
		a = -a * x* x / (n*(n + 1));
		s += a;
		n += 2;
	} while (mfabs(a) > eps);
	return s;
}

double mytg(double number, double eps) {
	return mysin(number, eps) / mycos(number, eps);
}

double myctg(double number, double eps) {
	return  mycos(number, eps) / mysin(number, eps);
}

double mylog(double num, double eps) {
	if (num <= 0)
		return 0;
	double a = (num - 1) / (num + 1), s = a, n = 1;
	do {
		s += a *= n * (num - 1) * (num - 1) / ((n + 2)*(num + 1)*(num + 1));
		n += 2;
	} while (mfabs(a) > eps);
	s *= 2;
	return s;
}

double myexp(double num, double eps) {
	double e = 1, a = 1, s = 1;
	unsigned int n = 0;
	do
		s += a *= num / (++n);
	while (mfabs(a) > eps);
	return s;
}

double mypow(double num, double power) {
	return myexp(power*mylog(num));
}



double mypow(double num, int power) {
	double d = 1;
	bool flg = 0;
	if (power != 0) {
		flg = 1;
		power = mfabs(power);
		for (int i = 1; i <= power; i++)
			d *= num;
	}
	if (flg) {
		d = 1 / d;
	}
	return d;
}

double mfabs(double num) {
	return (num < 0) ? -num : num;
}