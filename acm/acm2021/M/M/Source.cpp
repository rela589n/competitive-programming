#include <bits/stdc++.h>

long long Calculate(long long* arr, const long long& l, const long long& r)
{
	long long sum = 0;
	for (long long i = l; i <= r - 1; i++)
	{
		for (long long j = i + 1; j <= r; j++)
		{
			if (i != j)
			{
				sum += arr[j] * arr[i];
			}
		}
	}
	return sum;
}

int main()
{
	long long kMaxSize;
	std::cin >> kMaxSize;

	if (kMaxSize == 1)
	{
		std::cout << 1 << std::endl;
		return 0;
	}

	long long arr[kMaxSize];
	for (long long i = 0; i < kMaxSize; i++)
	{
		std::cin >> arr[i];
	}


	long long counter = kMaxSize;
	for (long long l = 0; l < kMaxSize - 1; l++)
	{
		for (long long r = l + 1; r < kMaxSize; r++)
		{
			if (Calculate(arr, l, r) % 3 == 0)
			{
				++counter;
			}
		}
	}
	std::cout << counter << std::endl;

	return 0;
}

/*

#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long

#define $ auto

using namespace std;

int main() {

	ll n;
	cin >> n;

	$ vec = vector<ll>(n);




	return 0;
}


*/