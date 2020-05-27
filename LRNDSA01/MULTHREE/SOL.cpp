#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main() {
    int T;
    cin >> T;
    while (T--) {
        lld K;
        lld d0, d1;
        cin >> K >> d0 >> d1;

        lld sum = 0;

        lld d2 = (d0 + d1);

        if (K == 2) {
            sum = d0 + d1;
        }

        else if (K == 3) {
            sum = d0 + d1 + d2 % 10;
        }

        else {
            // 2, 4, 8, 6 -> cycle formed
            lld S = (2 * d2) % 10 + (4 * d2) % 10 + (8 * d2) % 10 + (6 * d2) % 10;

            sum = d0 + d1 + d2 % 10 + ((K - 3) / 4) * S;

            K -= 3;

            if (K % 4 == 1)
                sum += (2 * d2) % 10;
            if (K % 4 == 2)
                sum += (2 * d2) % 10 + (4 * d2) % 10;
            if (K % 4 == 3)
                sum += (2 * d2) % 10 + (4 * d2) % 10 + (8 * d2) % 10;
        }

        if (sum % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}