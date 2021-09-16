#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long;
#define ull unsigned long long;
const int N = 503;

int n, arr[N], limit, sum, temp[N], temp1[N], temp2[N];
inline bool checkBin(int x)
{
	if (sum % x)
		return false;

	bool sorted = true;



	for (int i = 1; i <= n; i++) {
		temp1[i] = arr[i] % x;
	}


	

	if (!sorted) {
		copy(begin(temp1), end(temp1), begin(temp));

		sort(temp + 1, temp + 1 + n);
	}

	int l = 1, r = n, opCount = 0;

	while (l < r && opCount <= limit + 3)
	{
		if (temp[l] % x == 0)
		{
			l++;
			continue;
		}
		if (temp[r] % x == 0)
		{
			r--;
			continue;
		}
		int t = min(temp[l] % x, x - (temp[r] % x));
		temp[l] -= t;
		temp[r] += t;
		opCount += t;
	}

	return opCount <= limit;
}
int main()
{
	scanf("%d%d", &n, &limit);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (int i = sum; i >= 1; i--)
	{
		if (true)
		{

		}
		if (checkBin(i))
		{
			printf("%d\n", i);
			break;
		}
	}

	// system("pause");
	return 0;
}
/*
2 3
8 20
// 7

2 10
3 5
// 8

4 5
10 1 2 22
// 7

8 7
1 7 5 6 8 2 6 5
// 5
*/
/*
Severity  Code  Description  Project  File  Line  Suppression State
Error  C4996   'scanf': This function or variable may be unsafe. Consider using scanf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.  E20  C:\Users\elliot\source\repos\acm2019\E20\E20\Source.cpp  37

*/