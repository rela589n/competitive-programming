#include <iostream>

using namespace std;

int main() {
	int n, i;
	double v, current_v, speed, length[100], currentTime = 0, t;
	cout << "quant of gas station" << endl;
	cin >> n;
	--n;
	cout << "length between gas stations"<<endl;
	for (i = 0; i < n; i++)
		cin >> length[i];
	cout << "time: ";
	cin >> t;
	cout << "volume: ";
	cin >> v;
	current_v = v;
	cout << "speed: ";
	cin >> speed;
	for (i = 0; i < n; i++) {
		cout << "i = \t" << i << endl;
		int kilometers = current_v * 10;
		if (kilometers >= length[i]) {
			current_v -= length[i] / 10.;
			currentTime += length[i] / speed;
		}
		else if (v * 10 >= length[i]) {
			current_v = v;
			currentTime += 1/6.;
			--i;
		}
		else {
			currentTime = 0;
			break;
		}
	}
	if (currentTime) {
		if (currentTime < t)
			cout << "You can do it\n";
		else
			cout << "Don\'t start!! you will lose!!\n";
		cout<< "You will finish in " << currentTime << "hours";
	}
	else {
		cout << "you will not reach the finish!";
	}
	system("pause");
	return 0;
}