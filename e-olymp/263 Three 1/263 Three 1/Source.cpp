#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define Int long long
#define ll Int
#define dbl long double

bool _flag_forelse = false;
#define For(loop) for(Int loop)

#define forI(n) For(i = 0; i < n; ++i)
#define forJ(m) For(j = 0; j < m; ++j)
#define forK(l) For(k = 0; k < l; ++k)

#define Forelse(loop) forelse(Int loop)
#define forelse(loop) _flag_forelse = false; for (loop, _flag_forelse=true)
#define empty bool __flag_forelse_copy = _flag_forelse; _flag_forelse = true;  if(!__flag_forelse_copy)

#define readI(var) Int var; cin >> var;
#define readF(var) double var; cin >> var;
#define readD(var) dbl var; cin >> var;

#define unless(condition)if(!condition)

#define $ auto
#define mkarr(size, type) new Int[size];
#define _matrix(rows, cols, type) vector<vector<type>>(rows, vector<type>(cols))
#define matrix(rows, cols) _matrix(rows, cols, Int)

#define _line(size, type) vector<type> (size)
#define line(size) _line(size, ll)
#define use(space) using namespace space

#define print_vector(vec, delim) forI(vec.size()) { cout << vec[i] << delim; }

use(std);

bool contains(Int source) {
	string str = to_string(source);

	return str.find("111") != string::npos;
}

Int n;
Int counter = 0;


void bruteForce(Int current, int depth) {
	if (depth >= n) {
		if (!(contains(current))) {
			++counter;
		}

		return;
	}

	bruteForce(current * 10 + 1, depth + 1);
	bruteForce(current * 10 + 2, depth + 1);
}

void prePrint(int _n, int _counter) {
	cout << "case " << _n << ": \n";
	cout << "	cout << " << _counter << ";\n";
	cout << "break;\n";
}

/*
50 => 19426970897100

*/

int main() {
	cin >> n;
	
	ll last1 = 1, last2 = 1, last3 = 2, current = 2;
	For(i = 2; i <= n; ++i) {
		current = (last1 + last2 + last3) % 12345;
		
		last1 = last2;
		last2 = last3;
		last3 = current;
	}

	cout << current << endl;

	/*For(i = 1; i <= 30; ++i) {
		n = i;
		counter = 0;

		//cout << "case " << n << ": \n";
		bruteForce(0, 0);
		cout << counter << ";\n";
		//cout << "break;\n";
	}*/


	//system("pause");
	return 0;
}

/*
++1
++3
++5
++9

+2
+3
+6
+11
+20


// last3

x + y + z = 7
x + 2 + 4 = 7
x = 1

1;
1;
2; y
4; z
7; 
13; = x + y + z
24;
44;
81;
149;
274;
504;
927;
1705;
3136;
5768;
10609;
19513;


case 1:
cout << 2;
break;
case 2:
cout << 4;
break;
case 3:
cout << 7;
break;
case 4:
cout << 13;
break;
case 5:
cout << 24;
break;
case 6:
cout << 44;
break;
case 7:
cout << 81;
break;
case 8:
cout << 149;
break;
case 9:
cout << 274;
break;
case 10:
cout << 504;
break;
case 11:
cout << 927;
break;
case 12:
cout << 1705;
break;
case 13:
cout << 3136;
break;
case 14:
cout << 5768;
break;
case 15:
cout << 10609;
break;
case 16:
cout << 19513;
break;
case 17:
cout << 35890;
break;
case 18:
cout << 66012;
break;
case 19:
cout << 121415;
break;
case 20:
cout << 1048576;
break;
case 21:
cout << 2097152;
break;


*/