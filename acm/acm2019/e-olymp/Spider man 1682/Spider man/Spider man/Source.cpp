#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;


int main()
{
	ld n;
	cin >> n;

	ll counter = 1l;
	ld base = 180 - 2 * n;

	while (60 < base && base < 180) {
		ld nxt = 180 - (2 * (180 - base));
		counter += 1;

		if (nxt <= 0 || nxt >= 180) {
			break;
		}

		base = nxt + 180 - (n + base);
	}

	if (n == 60) {
		cout << 2 << endl;
	}
	else {
		cout << counter << endl;
	}
	
	system("pause");
	return 0;
}
/*

n = float(input())

base = 180 - 2 * n
count = 1

while 60 < base < 180:
	nxt = 180 - (2 * (180 - base))
	count += 1

	if nxt <= 0 or nxt >= 180:
		break

	base = nxt + 180 - (n + base)

	# base = 180 - (n + (180 - base))

if n == 60:
	print(2)
else:
	print(int(round(count)))

# input()

*/