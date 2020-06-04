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

    int N, M;
    cin >> N >> M;

    std::vector<lld> A(N);
    std::vector<lld> B(M);

    fori(i, 0, N) {
        cin >> A[i];
    }

    fori(i, 0, N) {
        cin >> B[i];
    }

    auto minA = std::min_element(ALL(A));
    auto minA_idx = std::distance(std::begin(A), minA);

    auto maxB = std::max_element(ALL(B));
    auto maxB_idx = std::distance(std::begin(B), maxB);

    // if A and B are sorted then
    // A1 + B1 < A1 + B2 < A1 + B3 . . . < A1 + BM
    // < A2 + BM < A3 + BM < A4 + BM < . . . < AN + BM

    fori(i, 0, M) {
        cout << minA_idx << ' ' << i << endl;
    }

    fori(i, 0, N) {
        if (i != minA_idx) {
            cout << i << ' ' << maxB_idx << endl;
        }
    }

    return 0;
}

// 25 PTS
// int N, M;
// cin >> N >> M;

// std::vector<std::pair<int, int>> A(N);
// std::vector<std::pair<int, int>> B(M);

// fori(i, 0, N) {
//     cin >> A[i].first;
//     A[i].second = i;
// }

// fori(i, 0, N) {
//     cin >> B[i].first;
//     B[i].second = i;
// }

// std::sort(ALL(A));
// std::sort(ALL(B));

// // if A and B are sorted then
// // A1 + B1 < A1 + B2 < A1 + B3 . . . < A1 + BM
// // < A2 + BM < A3 + BM < A4 + BM < . . . < AN + BM

// fori(i, 0, M - 1) {
//     cout << A[0].second << ' ' << B[i].second << '\n';
//     // cout << A[0].second << ' ' << B[i].second << ": " << A[0].first + B[i].first << '\n';
// }

// fori(i, 0, N) {
//     cout << A[i].second << ' ' << B[B.size() - 1].second << '\n';
//     // cout << A[i].second << ' ' << B[B.size() - 1].second << ": " << A[i].first + B[B.size() - 1].first << '\n';
// }