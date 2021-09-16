#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class NumberSystemConverter {
private:
	//������ �������� �������� �����
	vector<int> a;
	//�������� ������� ���������
	int initial;
public:
	//�����������, �������� 2 ���������: ������ ��������� �����, �������� ������� ���������
	NumberSystemConverter(string str, int initial) {
		this->initial = initial;
		//������� ����� ��������� ����� � ������
		a = vector<int>(str.begin(), str.end());
		for (int i = 0; i < a.size(); ++i) {
			this->a[i] -= '0';
		}
	}
	//��������� ������ � �����, ������ ������������ �������� ���������� -1
	int charToInt(char c) {
		if (c >= '0' && c <= '9' && (c - '0') < this->initial) {
			return c - '0';
		}
		else {
			if (c >= 'A' && c <= 'Z' && (c - 'A') < this->initial) {
				return c - 'A' + 10;
			}
			else {
				return -1;
			}
		}
	}
	//��������� ����� � ������
	static char intToChar(int c) {
		if (c >= 0 && c <= 9) {
			return c + '0';
		}
		else {
			return c + 'A' - 10;
		}
	}
	//�������� ��������� ����� ����� � ����� ������� ���������
	int nextNumber(int final) {
		int temp = 0;
		for (int i = 0; i < this->a.size(); ++i) {
			temp = temp * this->initial + this->a[i];
			a[i] = temp / final;
			temp = temp % final;
		}
		return temp;
	}
	//���������� true - ���� ������ ������� �� ����� ����� � false � ��������� ������
	bool zero() {
		for (int i = 0; i < this->a.size(); ++i) {
			if (a[i] != 0) {
				return false;
			}
		}
		return true;
	}
	//������������ �������� ����� � �������� ������� ���������
	string convertTo(int final) {
		vector<int> b;
		int size = 0;
		do {
			b.push_back(this->nextNumber(final));
			++size;
		} while (!this->zero());

		string sTemp = "";
		for (int i = b.size() - 1; i >= 0; --i) {
			sTemp += intToChar(b[i]);
		}
		return sTemp;
	}
};

bool replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

int main() {
	string str;
	getline(cin, str);
	
	replace(str, "$name", "Eugene");
		
	cout << str;

	str.length();
	system("pause");
	return 0;
}