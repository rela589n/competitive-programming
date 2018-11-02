#include <iostream>

using namespace std;

int main() {
	float a, b, c;
	// вводим сторони
	cin >> a >> b >> c;
	// проверка на то шо це трикутник
	if (a + b > c && b + c > a && a + c > b) {

		/*найдемо саму довгу сторону, і одночасно інших дві сторони 
		 *(якщо трикутник прямокутний, то ці дві сторони будуть катетами),
		 */ 

		float max = a, k1 = b, k2 = c;
		if (b > max) {
			max = b;
			k1 = a;
			k2 = c;
		}
		if (c > max) {
			max = c;
			k1 = b;
			k2 = a;
		}
		
		/*
		 *І провіряєм за формулою, яку сказав Стефан
		 *(Вона випливає з теореми Піфагора)
		 */
		if (max*max < k1*k1 + k2 * k2)
			cout<<"acute"<<endl;
		else if (max*max > k1*k1 + k2 * k2)
			cout << "obtuse" << endl;
		else
			cout << "rectangular" << endl;
	}
	else
		cout << "triangle with such sides is not exists" << endl;


	system("pause");
	return 0;
}