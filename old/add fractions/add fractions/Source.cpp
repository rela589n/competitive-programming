#include <iostream>

using namespace std;
unsigned int LCD(unsigned int a, unsigned int b);
int main() {
	unsigned int a, b, c, d, bc, dc, LM, LD, C, Z;
	cin >> a >> b >> c >> d;
	
	LD = LCD(b, d);
	LM = b / LD * d;

	C = LM / b * a + LM / d * c;
	Z = LM;

	LD = LCD(C, Z);

	cout << C / LD << endl << Z / LD << endl;
	system("pause");
	return 0;
}

unsigned int LCD(unsigned int a, unsigned int b) {
	while ((a > 0) && (b > 0)) {
		(a > b) ? a %= b : b %= a;
	}
	return a + b;
}
