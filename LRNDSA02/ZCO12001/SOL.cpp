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
    int N; cin >> N;

    int bracs[500000];
    for (int i = 0; i < N; i++) {
        cin >> bracs[i];
    }

    int depth = 0;
    int nested = 0;
    int nest_start = 0;

    pair<int, int> depth_info{0, 0};
    pair<int, int> nest_info{0, 0};

    for (int i = 0; i < N; i++) {
        if (depth == 0) {
            nested = 0;
            nest_start = i + 1;
        }

        nested++;

        if (bracs[i] == 1)
            depth++;
        else
            depth--;

        // cout << "#DEPTH: " << depth << '\n';

        if (depth > depth_info.first) {
            depth_info.first = depth;
            depth_info.second = i + 1;
        }

        if (nested > nest_info.first) {
            nest_info.first = nested;
            nest_info.second = nest_start;
        }
    }

    cout << depth_info.first << ' ' << depth_info.second << ' ' << nest_info.first << ' ' << nest_info.second << '\n';

    return 0;
}