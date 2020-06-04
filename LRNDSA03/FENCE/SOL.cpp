// COMPILER OPTIMIZATION
#ifdef ONLINE_JUDGE
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#endif

// INCLUDES
#include <bits/stdc++.h>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <iostream>
#include <regex>
#include <string>

using namespace __gnu_pbds;
using namespace std;

// DEFINES
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(NULL);               \
    std::cout.tie(NULL)
#define lld long long int
#define pii std::pair<int, int>
#define ff first
#define ss second
#define CLR(_a, _init) memset(_a, _init, sizeof(_a))
#define ODD(_num) (((_num)&1) == 0 ? (0) : (1))
#define EVEN(_num2) (!(((_num2)&1) == 0 ? (0) : (1)))
#define fori(_ii, _begin, _end) for (lld _ii = _begin; _ii < _end; _ii++)
#define ALL(_v) std::begin(_v), std::end(_v)
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

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        std::map<std::pair<int, int>, int> points;

        fori(i, 0, K) {
            int X, Y;
            cin >> X >> Y;
            points[{X, Y}] = 4;
        }

        for (auto point : points) {
            auto X = point.first.first;
            auto Y = point.first.second;

            if (points.count({X + 1, Y}) > 0)
                points[{X, Y}]--;

            if (points.count({X - 1, Y}) > 0)
                points[{X, Y}]--;

            if (points.count({X, Y + 1}) > 0)
                points[{X, Y}]--;

            if (points.count({X, Y - 1}) > 0)
                points[{X, Y}]--;
        }

        lld sum = 0;

        for (auto point : points) {
            sum += point.second;
        }

        cout << sum << '\n';
    }

    return 0;
}