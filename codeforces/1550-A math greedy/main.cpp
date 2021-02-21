#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        int s;
        cin >> s;

        int iterations = 1;
        int total = 1;
        int number = 1;

        while (total < s) {
            number = number + 2;
            total += number;

            ++iterations;
        }

        cout << iterations << endl;
    }
    return 0;
}
