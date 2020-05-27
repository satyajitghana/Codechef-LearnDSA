#include <bits/stdc++.h>

using namespace std;

#define lld long long int

static void print_arr(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        string s;
        cin >> s;
        int ascore, bscore, arem, brem;
        ascore = bscore = 0;
        arem = brem = N;

        int i;
        for (i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                // a shoot
                if (s.at(i) == '1') {
                    ascore++;
                }
                arem--;
                // if ascore > bscore + rem_all goals of b then a wins
                // also if bscore > ascore + rem_all goals of a then b wins
                if ((bscore + brem < ascore) or (ascore + arem < bscore))
                    break;
            } else {
                // b shoot
                if (s.at(i) == '1') {
                    bscore++;
                }
                brem--;
                if ((bscore + brem < ascore) or (ascore + arem < bscore))
                    break;
            }
        }
        cout << (i == s.length() ? i : i + 1) << '\n';
    }
    return 0;
}