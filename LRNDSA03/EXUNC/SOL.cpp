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

template <typename T>
inline void print_set(set<T> s) {
    for (auto e : s) {
        cout << e << ' ';
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

    int N, Q;
    cin >> N >> Q;
    std::vector<int> A(N);
    std::set<int> partitions;

    fori(i, 0, N) {
        cin >> A[i];
    }

    partitions.insert(0);
    fori(i, 1, N) {
        if (A[i] % A[i - 1] == 0)
            continue;
        else
            partitions.insert(i);
    }

    auto query = [&](int i) {
        auto idx = partitions.upper_bound(i);
        return *std::prev(idx);
    };

    // for (auto e : partitions) {
    //     cout << e << ": " << A[e] << "\n";
    // }

    // cout << query(0);

    while (Q--) {
        // index is 1 based
        int type, index;
        cin >> type >> index;

        // make it 0 based
        index--;

        if (type == 1) {
            int X;
            cin >> X;
            A[index] = X;

            if (index > 0) {
                // A[idx] and A[idx-1] weren't in same subarray but can now be in the same subarray
                if ((query(index) != query(index - 1)) and (A[index] % A[index - 1] == 0))
                    partitions.erase(index);

                // A[idx] and A[idx-1] were in same subarray, but now they cant be
                if ((query(index) == query(index - 1)) and (A[index] % A[index - 1] != 0))
                    partitions.insert(index);
            }

            if (index < N) {
                // A[idx] and A[idx+1] weren't in same sub array but now can be in the same subarray
                if ((query(index + 1) != query(index)) and (A[index + 1] % A[index] == 0))
                    partitions.erase(index + 1);

                // A[idx] and A[idx+1] were in same sub array, but now can't be
                if ((query(index + 1) == query(index)) and (A[index + 1] % A[index] != 0))
                    partitions.insert(index + 1);
            }

        } else if (type == 2) {
            cout << query(index) + 1 << '\n';
        }
    }

    return 0;
}