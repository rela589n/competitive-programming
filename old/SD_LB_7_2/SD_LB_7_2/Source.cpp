#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char message[200], a, b, decoded_message[200] = "";
	int m_indx = 0, consonant = 0, luod = 0, len, i, cost = 0, k, l;
	cin.getline(message, 200);	
	cin.get(a);
	cin.get();
	cin.get(b);
	cin.get();
	cin >> k >> l;
	len = strlen(message);
	for (i = 0; i < len; i++) {
		if (message[i] == a)
			cost += 10;
		else if (message[i] == b)
			cost++;
		else {
			switch (message[i]) {
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
			case '�':
				if (++luod % k == 0)
					decoded_message[m_indx++] = message[i];
				break;
			case ' ':
				decoded_message[m_indx++] = message[i];
				break;
			default:
				if (++consonant % l == 0)
					decoded_message[m_indx++] = message[i];
			}
		}
	}
	cout << decoded_message <<"\n�������: " << cost << endl;
	//����������q���q��q��q��r r��r����������������
	system("pause");
	return 0;
}