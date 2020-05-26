#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int max_speed[10000];

        for (int i = 0; i < N; i++)
            cin >> max_speed[i];

        int cnt = 0;

        for (int i = 0; i < N - 1; i++) {
            if (max_speed[i + 1] > max_speed[i]) {
                max_speed[i + 1] = max_speed[i];
                cnt++;
            }
        }

        cout << (N - cnt) << '\n';
    }

    return 0;
}