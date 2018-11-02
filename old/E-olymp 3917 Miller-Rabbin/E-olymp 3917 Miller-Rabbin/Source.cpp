#include <iostream>

using namespace std;
typedef unsigned long long Int;


Int gcd(Int a, Int b) {

	while (a && b) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}

	return a + b;
}

void transform_num(Int n, Int & p, Int & q)
{
	Int p_res = 0;
	while (!(n & 1))
	{
		++p_res;
		n >>= 1;
	}
	p = p_res;
	q = n;
}

void mulmod(Int & a, Int b, const Int & n)
{
	// ������� ������, ������� ������ ��� ������� ����������
	a *= b;
	a %= n;
}

Int powmod(Int a, Int k, const Int & n)
{
	Int res = 1;
	while (k)
		if (k & 1)
		{
			mulmod(res, a, n);
			--k;
		}
		else
		{
			mulmod(a, a, n);
			k >>= 1;
		}
	return res;
}


bool miller_rabin(Int n, Int b)
{

	// ������� ��������� ����������� ������
	if (n == 2)
		return true;
	if (n < 2 || !(n & 1))
		return false;

	// ���������, ��� n � b ������� ������ (����� ��� �������� � ������)
	// ���� ��� �� ������� ������, �� ���� n �� ������, ���� ����� ��������� b
	if (b < 2)
		b = 2;
	for (Int g; (g = gcd(n, b)) != 1; ++b)
		if (n > g)
			return false;

	// ��������� n-1 = q*2^p
	Int n_1 = n;
	--n_1;
	Int p, q;
	transform_num(n_1, p, q);

	// ��������� b^q mod n, ���� ��� ����� 1 ��� n-1, �� n ������� (��� �������������)
	Int rem = powmod(Int(b), q, n);
	if (rem == 1 || rem == n_1)
		return true;

	// ������ ��������� b^2q, b^4q, ... , b^((n-1)/2)
	// ���� �����-���� �� ��� ����� n-1, �� n ������� (��� �������������)
	for (Int i = 1; i < p; i++)
	{
		mulmod(rem, rem, n);
		if (rem == n_1)
			return true;
	}

	return false;

}

int main() {
	Int n;
	cin >> n;

	if (miller_rabin(n, 2)) {
		cout << "True";
	}
	else {
		cout << "False";
	}


	return 0;
}

