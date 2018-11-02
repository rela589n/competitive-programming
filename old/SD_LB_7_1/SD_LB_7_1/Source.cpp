#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;
void burn_spaces(char *a);

int main() {
	int n, i = 0, k = 0, wordlen = 0, words_indx = 0, words[100][2];
	char info[100], buf[100] = "", pairWords[150] = "";
	gets_s(info);
	burn_spaces(info);
	if (strlen(info) < 2) {
		cout << "very short string";
		system("pause");
		return 0;
	}
	for (;info[i]; i++) {
		if (info[i] == ',' ||
			info[i] == '.' ||
			info[i] == '-' ||
			info[i] == ':' ||
			info[i] == ';' ||
			info[i] == '?' ||
			info[i] == '!')
			k++;
		
		if (!isalnum(info[i])) {
			if(strlen(buf)) {
				if (wordlen % 2 == 0) {
					strcat_s(pairWords, buf);
					strcat_s(pairWords, ", ");
				}
				words[words_indx][0] = i - wordlen;
				words[words_indx++][1] = i - 1;
			}
			strcpy_s(buf, "");
			wordlen = 0;
		}
		else {
			char letter[2];
			letter[0] = info[i];
			letter[1] = '\0';
			strcat_s(buf, letter);
			wordlen++;
		}

	}
	if(strlen(buf)){
		if (wordlen % 2 == 0){
			strcat_s(pairWords, buf);
			strcat_s(pairWords, "\0");
		} 
		else if (strlen(pairWords) > 1)
			pairWords[strlen(pairWords) - 2] = '\0';
		else
			pairWords[0] = '\0';
		words[words_indx][0] = i - wordlen;
		words[words_indx++][1] = i - 1;
	}
	else {
		pairWords[strlen(pairWords) - 2] = '\0';
	}

	
	cout << "\nquantity of punctuation marks: " << k << endl;
	if (strlen(pairWords))
		cout << "words with pair length: " << pairWords;
	else
		cout << "there were no words with pair length";
	cout << "\n\n";
	cout << "words with reversed first and last letters: ";
	for (i = 0; i < words_indx; i++) {
		if (words[i][1] == words[i][0])
			cout << info[words[i][1]];
		else {
			cout << info[words[i][1]];
			for (int j = words[i][0] + 1; j < words[i][1]; j++) {
				cout << info[j];
			}
			cout << info[words[i][0]];
		}
		if (words_indx - i > 1)
			cout << ", "; 
	}
	system("pause");	
	return 0;
}

//cin.ignore(numeric_limits<streamsize>::max(), '\n');
void burn_spaces(char *a) {
	int i, len = strlen(a), l = 0, r = len - 1, indx = 1;
	while (a[l] == ' ') {
		l++;
	}
	while (a[r] == ' ') {
		r--;
	}
	if (r - l <= 0){
		r = 1;
		l = 0;
	}
	char *b = new char[r - l];
	b[0] = a[l];
	for (i = l + 1; i <= r; i++) {
		if (!(a[i] == ' ' && a[i - 1] == ' ')) {
			b[indx++] = a[i];
		}
	}
	for (i = 0; i < indx; i++) {
		a[i] = b[i];
	}
	a[indx] = '\0';
}