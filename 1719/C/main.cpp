#include <bits/stdc++.h>

using namespace std;

#define MAX_WIN 2147483647

vector<int> arr = vector<int>(100000 + 1);

int main() {
    int te;
    cin.tie(nullptr);

    cin >> te;

    for (int t = 0; t < te; ++t) {
        int n;
        int qe;
        cin >> n >> qe;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> win_start_step = vector<int>(n + 1, -1);
        vector<int> won_count = vector<int>(n + 1, 0);

        int lastWinner = max(arr[0], arr[1]);

        win_start_step[lastWinner] = 0;
        won_count[lastWinner] = 1;

        for (int ptr = 2; ptr < n; ++ptr) {
            lastWinner = max(lastWinner, arr[ptr]);

            if (~win_start_step[lastWinner]) {
                ++won_count[lastWinner];
            } else {
                win_start_step[lastWinner] = ptr - 1;
                won_count[lastWinner] = 1;
            }
        }

        if (win_start_step[n] == -1) {
            win_start_step[n] = 0;
        }

        won_count[n] = MAX_WIN;

        for (int q = 0; q < qe; ++q) {
            int i, k;
            cin >> i >> k;
            --i;
            --k;

            i = arr[i];

            if (win_start_step[i] == -1) {
                cout << 0 << endl;
                continue;
            }

            if (k < win_start_step[i]) {
                cout << 0 << endl;
                continue;
            }

            int ro = k - win_start_step[i] + 1;

            cout << min(ro, won_count[i]) << endl;
        }
    }

    return 0;
}
