#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main() {
    int T;
    cin >> T;

    while (T--) {
        lld G;
        cin >> G;

        while (G--) {
            lld I, N, Q;
            cin >> I >> N >> Q;

            if (N % 2 == 0) {
                cout << N / 2 << '\n';
                continue;
            }

            // N is odd
            lld half = N / 2;

            lld heads, tails;
            heads = tails = half;

            if (I == 1)
                tails++;
            else
                heads++;

            if (Q == 1) {
                cout << heads << '\n';
            }

            if (Q == 2) {
                cout << tails << '\n';
            }
        }
    }

    return 0;
}