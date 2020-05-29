#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define lld long long int

int main() {
    int N;
    cin >> N;

    lld budgets[500000];

    for (int i = 0; i < N; i++)
        cin >> budgets[i];

    // 40 3 65 33 21

    // 3 21 33 40 65

    // [ 3 * 5, 21 * 4, 33 * 3, 40 * 2, 65 * 1 ]

    std::sort(budgets, budgets + N);

    lld min_rev = 0;

    for (int i = 0; i < N; i++) {
        min_rev = std::max(min_rev, (budgets[i] * (N - i)));
    }

    cout << min_rev << '\n';

    return 0;
}
