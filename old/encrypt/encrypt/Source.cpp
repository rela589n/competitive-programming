#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <windows.h>
using namespace std;

bool is_in_arr(char value, char *arr, int len);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	char message[200], decoded_message[200], a, b, consonant_letters[46] = "¥´ÁÂÃÄÆÉÊËÌÍÏĞÑÒÔÕÖ×ØÙÜáâãäæçéêëìíïğñòôõö÷øùü", luod_letters[21] = "ª¯²³º¿ÀÅÈÎÓŞßàåèîóşÿ";
	int consonant = 0, luod = 0, len, i, cost = 0, c, l, j = 0, m_indx = 0;
	cout << "Enter string:" << endl;
	cin.getline(message, 200);
	cout << "Enter levels for luod and consonant encrypting: " << endl;
	cin >> l >> c;
	
	
	char *encrypted_message = new char[3*strlen(message)*max(c,l)];
	
	for (i = 0; message[j]; i++) {
		if (is_in_arr(message[j], luod_letters, 20)) {
			if (luod == l - 1) {
				encrypted_message[i] = message[j++];
				luod = 0;
			} 
			else if (consonant < c - 1 && rand() % 2) {
				encrypted_message[i] = consonant_letters[rand() % 45];
				consonant++;
			}
			else {
				encrypted_message[i] = luod_letters[rand() % 20];
				luod++;
			}
		}
		else if (is_in_arr(message[j], consonant_letters, 45)) {
			if (consonant == c - 1) {
				encrypted_message[i] = message[j++];
				consonant = 0;
			}
			else if (luod < l - 1 && rand() % 2) {
				encrypted_message[i] = luod_letters[rand() % 20];
				luod++;
			}
			else {
				encrypted_message[i] = consonant_letters[rand() % 45];
				consonant++;
			}
		}
		else
			encrypted_message[i] = message[j++];
	}
	encrypted_message[i] = '\0';
	cout << encrypted_message << endl;

	/*
	consonant = luod = 0;
	for (i = 0; encrypted_message[i]; i++) {
		if (message[i] == a)
			cost += 10;
		else if (message[i] == b)
			cost++;
		else {
			if (is_in_arr(message[i], luod_letters, 20) || ) {

			}
			//message[i], luod_letters, 20
			if((++luod % c == 0) || 
				is_in_arr(message[i], consonant_letters, 45) && (++consonant % l == 0))
					decoded_message[m_indx++] = encrypted_message[i];
		}
	}
	*/
	//ìàğÊóôğïàëqëëÿqğåºqêìqóîr rêórğòåôëåëåêìàôîğìí
	system("pause");
	return 0;
}

//Êóïëÿºìî òåëåôîí

bool is_in_arr(char value, char *arr, int len = strlen(arr)) {
	int l = 0, r = len - 1, c;
	while (r > l) {
		c = (r + l) / 2;
		if (arr[c] > value) {
			r = c - 1;
		}
		else if (arr[c] < value) {
			l = c + 1;
		}
		else {
			l = r = c;
		}
	}
	if (arr[l] == value)
		return 1;
	return 0;
}
