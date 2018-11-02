#include <iostream>
#include <ctime>

using namespace std;

int main() {
	float rate = 0.2, avarageY = 0, avarageG = 0, y[15], g[20], d;
	unsigned int Y[15], G[20];
	cout << "enter a cost of a day:" << endl;
	cin >> d;
	
	cout << "Y: " << endl;
	for (int i = 0; i < 15; i++) {
		Y[i] = rand() % 31 + 1;
		y[i] = d * Y[i] * (1 - rate);
		avarageY += y[i];
		cout << Y[i] << "\t";
	}
	avarageY /= 15.;
	cout << endl << "G: " << endl;
	for (int i = 0; i < 20; i++) {
		G[i] = rand() % 31 + 1;
		g[i] = d * G[i] * (1 - rate);
		avarageG += g[i];
		cout << G[i] << "\t";
	}
	avarageG /= 20.;
	cout.precision(5);
	cout<<endl<<endl << "y: " << endl;
	for (int i = 0; i < 15; i++)
		cout << y[i] << '\t';
	cout << endl << endl << "g: " << endl;
	for (int i = 0; i < 15; i++)
		cout << g[i] << '\t';
	cout << endl << "Avarage earning on unit Y: " << avarageY << endl;
	cout << "Avarage earning on unit G: " << avarageG << endl;
	system("pause");
	return 0;
}