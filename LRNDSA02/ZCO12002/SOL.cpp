#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

// DEFINES
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);               \
    std::cout.tie(NULL)
#define lld long long int
#define CLR(_a, _init) memset(_a, _init, sizeof(_a))
#define ODD(_num) (((_num)&1) == 0 ? (0) : (1))
#define EVEN(_num2) (!(((_num2)&1) == 0 ? (0) : (1)))
#define fori(_ii, _begin, _end) for (lld _ii = _begin; _ii < _end; _ii++)
#define DEBUG "DEBUG------"
#define watch(__x) cout << DEBUG << (#__x) << " : " << (__x) << endl

// HELPER FUNCTIONS
template <typename T>
inline void print_arr(T arr[], int N) {
    fori(i, 0, N) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
}
template <typename T>
inline void print_vec(vector<T> vec, int N) {
    fori(i, 0, N) {
        cout << vec[i] << ' ';
    }

    cout << '\n';
}

// LET THE GAMES BEGIN
int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, X, Y;
    cin >> N >> X >> Y;

    std::vector<lld> S(N), E(N);

    fori(i, 0, N) {
        cin >> S[i] >> E[i];
    }

    std::vector<lld> V(X), W(Y);

    fori(i, 0, X) {
        cin >> V[i];
    }

    fori(i, 0, Y) {
        cin >> W[i];
    }

    std::sort(begin(V), end(V));
    std::sort(begin(W), end(W));

    lld min = numeric_limits<lld>::max();

    fori(i, 0, N) {
        auto l = std::upper_bound(begin(V), end(V), S[i]) - begin(V) - 1;
        auto r = std::lower_bound(begin(W), end(W), E[i]) - begin(W);

        if (l >= 0 and r < Y)
            min = std::min(min, W[r] - V[l] + 1);
    }

    cout << min << '\n';

    return 0;
}