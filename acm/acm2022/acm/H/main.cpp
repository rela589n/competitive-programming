#include <bits/stdc++.h>

#define ll long long
#define ld long double

#define INF 2147483646

using namespace std;
ll n;
ll vec[2 * 100000 + 2];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return  0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    sort(vec, vec + n);
/*

    int l = 0, r = 1;
    ll minDiff = abs(vec[l] - vec[r]);
    ld maxRes = vec[l] * vec[r] * 1. / (ld)minDiff;

    for (int i = 1; i < n; ++i) {
        ll df = abs(vec[i] - vec[i - 1]);
        ld res = vec[i - 1] * vec[i] * 1. / (ld)minDiff;

        if (res > maxRes) {
            minDiff = df;
            l = i - 1;
            r = i;
            maxRes = res;
        }
    }*/

    int l = 0 , r = 1;
    ld maxRes = vec[0] * vec[1] * (abs(vec[0] - vec[1]));

    for (int i = 1; i < n; ++i) {
            // todo?: use ints
        ll cur = (vec[i - 1] * vec[i])* (abs(vec[i - 1] - vec[i])) ;

        if (maxRes < cur) {
            maxRes = cur;
            l = i - 1;
            r = i;
        }
    }




    ld mr = (ld)maxRes / ((abs(vec[l] - vec[r])) * (abs(vec[l] - vec[r])));

    //ld res = vec[l] * vec[r] * 1. / (ld)minDiff;

     //std::cout << std::fixed;
//printf("%+.10f\n", maxRes);
//cout << maxRes << endl;
//printf("%f", maxRes);
//    cout << sprintf("%#.2f\n",maxRes);
    ll m = mr;
//cout<< to_string(m).size()<< endl;
    cout.precision(10 + to_string(m).size());
    cout << mr;

    return 0;
}
