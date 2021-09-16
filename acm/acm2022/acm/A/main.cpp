#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define INF 2147483646

using namespace std;
ll n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;


    if (n % 5 == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll mod = n % 5;

    if (mod > 5 / 2) {
        cout << (5 - mod) << endl;
    }
    else {
        cout << mod << endl;
    }

    return 0;
}
