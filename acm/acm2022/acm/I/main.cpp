#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll inf = 1e9+7;

bool isUsed[200002] = {0};
ll weights[200002] = {0};
ll from[200002] = {0};
ll inputWeights[200002] = {0};

queue<pair<ll, ll>> q;

ll n = 0;
ll m = 0;

int main()
{
    for(ll i = 0; i <200002; i++) {
        from[i] = -1;
        weights[i] = inf;
    }

    cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        cin >> inputWeights[i];
    }

    sort(inputWeights, inputWeights + n);

    for (ll i = 1; i < n; i++) {
        pair<ll, ll> p;
        p.first = 0;
        p.second = i;
        q.push(p);
    }

    isUsed[0] = true;

    while (q.size()) {
        pair<ll, ll> p = q.front();
        q.pop();

        //cout << "p: " << p.first << ' ' << p.second << endl;

        ll w = (inputWeights[p.first] + inputWeights[p.second]) % m;
        if (from[p.second] == -1 || weights[p.second] >= w) {
            //cout << w << endl;
            weights[p.second] = w;
            from[p.second] = p.first;
        }

        if(!isUsed[p.second]) {
            for(ll i = 1; i < n; i++) {
                if (isUsed[i]) {
                    continue;
                }
                pair<ll, ll> pp;
                pp.first = p.second;
                pp.second = i;
                q.push(pp);
            }
            isUsed[p.second] = true;
        }
    }

    ll sum = 0;

    for (ll i =1; i<n;i++ ) {
        sum += weights[i];
    }

    cout << sum << endl;
    return 0;
}
