#include <iostream>
#include <ctime>
#include <algorithm>
//#include <string>

using namespace std;

int main()
{
	srand(time(NULL));

	char latin[30];
	latin[0] = 'A';
	latin[1] = 'B';
	latin[2] = 'C';
	latin[3] = 'D';
	latin[4] = 'E';
	latin[5] = 'F';
	latin[6] = 'G';
	latin[7] = 'H';
	latin[8] = 'I';
	latin[9] = 'J';
	latin[10] = 'K';
	latin[11] = 'L';
	latin[12] = 'M';
	latin[13] = 'N';
	latin[14] = 'O';
	latin[15] = 'P';
	latin[16] = 'Q';
	latin[17] = 'R';
	latin[18] = 'S';
	latin[19] = 'T';
	latin[20] = 'U';
	latin[21] = 'V';
	latin[22] = 'W';
	latin[23] = 'X';
	latin[24] = 'Y';
	latin[25] = 'Z';


	int len, palindromLen;

	cin >> len >> palindromLen;

	for (int i = 0; i < palindromLen; ++i) {
		cout << latin[7];
	}
	if (palindromLen < len) {
		cout << latin[0];
	}
	for (int i = palindromLen + 1; i < len; ++i) {
		cout << latin[i % 26];
	}

	return 0;
}
