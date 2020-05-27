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
        lld sum = 0;

        lld min = std::numeric_limits<long long int>::max();

        for (int i = 0; i < N; i++) {
            lld S;
            cin >> S;
            min = std::min(min, S);

            sum += min;
        }

        cout << sum << '\n';
    }
    return 0;
}