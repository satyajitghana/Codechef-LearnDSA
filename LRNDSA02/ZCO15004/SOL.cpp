// COMPILER OPTIMIZATION
#ifndef ONLINE_JUDGE
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#endif

// INCLUDES
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
#define DEBUG "DEBUG: "
#define watch(__x) DEBUG << (#__x) << " : " << (__x)
#define ALL(_v) std::begin(_v), std::end(_v)

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

struct point {
    int x, y;
};

// LET THE GAMES BEGIN
int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N;
    cin >> N;
    std::vector<point> points(N);

    const int xlim = 100000;
    const int ylim = 500;

    std::vector<int> top_points(xlim + 1), left(xlim + 1), right(xlim + 1);

    std::fill(ALL(top_points), ylim);
    std::fill(ALL(right), xlim);
    std::fill(ALL(left), 0);

    fori(i, 0, N) {
        int x, y;
        cin >> x >> y;

        top_points[x] = std::min(top_points[x], y);
    }

    std::stack<int> st;

    // for each of the upper points, find the right limits
    for (int x = 0; x <= xlim; x++) {
        while ((not st.empty()) and (top_points[x] < top_points[st.top()])) {
            // cout << watch(st.top()) << ", " << watch(x) << ", " << watch(top_points[x]) << ", " << watch(top_points[st.top()]) << '\n';
            right[st.top()] = x;
            st.pop();
        }

        st.push(x);
    }

    // clear the stack
    while (not st.empty())
        st.pop();

    // for each of the upper points, find the left limits
    for (int x = xlim; x >= 0; x--) {
        while ((not st.empty()) and (top_points[x] < top_points[st.top()])) {
            // cout << watch(st.top()) << ", " << watch(x) << ", " << watch(top_points[x]) << ", " << watch(top_points[st.top()]) << '\n';
            left[st.top()] = x;
            st.pop();
        }

        st.push(x);
    }

    int max = 0;

    for (int x = 0; x <= xlim; x++) {
        max = std::max(max, (right[x] - left[x]) * top_points[x]);
    }

    cout << max << '\n';

    return 0;
}