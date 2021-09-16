#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define INF 2147483646

using namespace std;
ll n;

unordered_map<ll, ll> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        if (t) {
            ++mp[t];
        }
    }

    //cout << mp.size() << en
    ll total = mp.size() - 1 + 1;
    ll gap = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second > 1) {
            gap += it->second;
        }
    }

    ll factorial = 1;

    for(int i = 1; i <= total; ++i) {
        factorial *= i;
        factorial %= 1000000000 + 7;
    }

    cout << (factorial + gap) % (1000000000 + 7) << endl;


    return 0;
}
