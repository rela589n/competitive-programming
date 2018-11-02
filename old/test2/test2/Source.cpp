#include <iostream>
#include <cstring>

bool is_latin(char sym);
using namespace std;
int main()
{
	char a[50], b[50];
	int p1 = 0, n, p2, ks = 0, kr = 0, c, choise;
	cout << "Input your string" << endl;
	cin.getline(a, 50);
	n = strlen(a);
	cin >> choise;
	switch (choise)
	{
	case 1:
		for (int i = 0; i < n; i++)
		{
			if (a[i] == ':') { p1 = i; break; }
		}
		for (int i = p1 + 1; i < n; i++) cout << a[i];
		break;

	case 2:
		for (int i = 0; i < n; i++)
		{
			if (a[i] == '.')
			{
				int k = i;
				for (int i = 0; i < n; i++)
				{
					if (a[i] == '.')
					{
						int k = i;
						for (int i = k + 2; i < n; i++)
						{
							if ((a[i] == 32) && (a[i + 1] != 32)) ks++;
						}
						if (a[0] != 32) ks++;
						if (a[n] != 32) ks++;
						ks--;
						if (ks % 2 != 0) kr++;
						ks = 0;
					}
				}
			}
		}
		cout << endl << "   kr= " << kr;
		break;
	case 3:
		for (int i=0; i < n; ++i)
		{
			if (a[i] == ',') {
				i++;
				do
					++i;
				while (i < n && is_latin(a[i]));
			}
			cout << a[i];
		}
		//default: cout << "nope";
	}
	cin.get();
	cin.get();
	return 0;
}


/*
Input your string
Lorem, ipsum dolor, sit amet
3
Lorem dolor amet

*/
bool is_latin(char sym) {
	char latin[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int l = 0, r = 51, center;
	while (r > l) {
		center = (l + r) / 2;
		if (sym < latin[center])
			r = center - 1;
		else if (sym > latin[center])
			l = center + 1;
		else
			r = l = center;
	}
	if (latin[l] == sym)
		return 1;
	return 0;
}