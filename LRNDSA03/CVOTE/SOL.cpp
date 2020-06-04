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

    int N, M;
    cin >> N >> M;

    std::unordered_map<string, string> name_country;
    std::unordered_map<string, int> chef_points;
    std::unordered_map<string, int> country_points;

    fori(i, 0, N) {
        string name, country;
        cin >> name >> country;

        name_country[name] = country;
        chef_points[name] = 0;
        country_points[country] = 0;
    }

    fori(i, 0, M) {
        string name;
        cin >> name;

        chef_points[name]++;
        country_points[name_country[name]]++;
    }

    auto max_country = std::make_pair<string, int>("", 0);

    for (const auto e : country_points) {
        if (e.second > max_country.second)
            max_country = e;

        else if (e.second >= max_country.second and e.first < max_country.first)
            max_country = e;
    }

    cout << max_country.first << endl;

    auto max_chef = std::make_pair<string, int>("", 0);

    for (const auto e : chef_points) {
        if (e.second > max_chef.second)
            max_chef = e;

        else if (e.second >= max_chef.second and e.first < max_chef.first)
            max_chef = e;
    }

    cout << max_chef.first << endl;

    return 0;
}