#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main() {
    int T;
    cin >> T;
    while (T--) {
        lld N;
        cin >> N;

        int Z = 0;

        while (N / 5 > 0) {
            Z += N / 5;
            N /= 5;
        }

        cout << Z << '\n';
    }

    return 0;
}