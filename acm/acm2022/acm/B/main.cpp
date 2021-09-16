#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define INF 2147483646

using namespace std;
ll n;
ll vec[2 * 100000 + 2];
ll sz = 0;



int main()
{

 //   ios_base::sync_with_stdio(0);
 //   cin.tie(0);
 //   cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i)     {
        cout << "? " << 1 << " " << (i + 1) << endl;
        cout.flush();

        cin >> vec[i];
    }

    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << vec[i];
    }

return 0;
}
