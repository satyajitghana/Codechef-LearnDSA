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

    int T;
    cin >> T;
    while (T--) {
        lld N, K;
        cin >> N >> K;

        vector<lld> A(N);

        fori(i, 0, N) {
            cin >> A[i];
        }

        lld l = 0;
        lld r = 0;
        lld max_len = 0;

        map<int, int> freq;

        while (r < N) {

            freq[A[r]]++;

            while (freq.size() >= K ) {
                freq[A[l]]--;
                if (freq[A[l]] == 0)
                    freq.erase(A[l]);
                l++;
            }

            max_len = std::max(max_len, r-l+1);

            r++;
        }

        cout << max_len << '\n';
    }
    return 0;
}