// template
#include <bits/stdc++.h>

using namespace std;

#define lld long long int

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;  // N type of street foods
        cin >> N;
        int S[100], V[100], P[100];
        // Si stores offer this food
        // Vi price of one piece of food
        // Pi people buy ith food, one piece each
        for (int i = 0; i < N; i++) {
            cin >> S[i] >> P[i] >> V[i];
        }

        int max = 0;

        for (int i = 0; i < N; i++) {
            S[i] += 1;  // chef's store is added
            auto num_people = P[i] / S[i];
            max = std::max(max, num_people * V[i]);
        }

        cout << max << '\n';
    }
    return 0;
}