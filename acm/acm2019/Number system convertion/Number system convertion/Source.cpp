#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class NumberSystemConverter {
private:
	//Вектор содержит исходное число
	vector<int> a;
	//Исходная система счисления
	int initial;
public:
	//Конструктор, содержит 2 параметра: строка исходного числа, исходная система счисления
	NumberSystemConverter(string str, int initial) {
		this->initial = initial;
		//Заносит числа исходного числа в вектор
		a = vector<int>(str.begin(), str.end());
		for (int i = 0; i < a.size(); ++i) {
			this->a[i] -= '0';
		}
	}
	//Переводит символ в число, вместо некорректных символов возвращает -1
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
	//Переводит число в символ
	static char intToChar(int c) {
		if (c >= 0 && c <= 9) {
			return c + '0';
		}
		else {
			return c + 'A' - 10;
		}
	}
	//Получает следующую цифру числа в новой системе счисления
	int nextNumber(int final) {
		int temp = 0;
		for (int i = 0; i < this->a.size(); ++i) {
			temp = temp * this->initial + this->a[i];
			a[i] = temp / final;
			temp = temp % final;
		}
		return temp;
	}
	//Возвращает true - если массив состоит из одних нулей и false в противном случае
	bool zero() {
		for (int i = 0; i < this->a.size(); ++i) {
			if (a[i] != 0) {
				return false;
			}
		}
		return true;
	}
	//Конвертирует исходное число в заданную систему счисления
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