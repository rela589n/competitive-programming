#include <iostream>

using namespace std;

int main() {
	float a, b, c;
	// ������ �������
	cin >> a >> b >> c;
	// �������� �� �� �� �� ���������
	if (a + b > c && b + c > a && a + c > b) {

		/*������� ���� ����� �������, � ��������� ����� �� ������� 
		 *(���� ��������� �����������, �� �� �� ������� ������ ��������),
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
		 *� �������� �� ��������, ��� ������ ������
		 *(���� ������� � ������� ϳ������)
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