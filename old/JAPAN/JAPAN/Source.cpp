#include <iostream>
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	//������, ������, �����, �����, �������, �쳿, ����, ����, �����, ����, ������, ����. 
	// 1996 - ������
	long int n;
	char names[12][12] = {"�����", "����", "������", "����",  "������", "������", "�����", "�����", "�������", "�쳿", "����", "����"};
	cin >> n;
	cout << "г�" << names[n % 12] << endl;
	system("pause");
	return 0;
}