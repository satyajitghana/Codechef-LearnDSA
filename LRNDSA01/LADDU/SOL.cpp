#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int acts;
        string origin;

        cin >> acts >> origin;

        string act_type[100];
        int act_points[100];

        for (int i = 0; i < acts; i++) {
            cin >> act_type[i];
            if (act_type[i] == "TOP_CONTRIBUTOR") {
                act_points[i] = 300;
            } else if (act_type[i] == "CONTEST_HOSTED") {
                act_points[i] = 50;
            } else if (act_type[i] == "CONTEST_WON") {
                int rank;
                cin >> rank;
                act_points[i] = 300 + (rank > 20 ? 0 : 20 - rank);
            } else {
                // BUG_FOUND
                cin >> act_points[i];
            }
        }

        // calculate total laddus
        int total = 0;
        for (int i = 0; i < acts; i++) {
            total += act_points[i];
        }
        // std::accumulate

        if (origin == "INDIAN") {
            cout << total / 200 << '\n';
        } else {
            // NON_INDIAN
            cout << total / 400 << '\n';
        }
    }

    return 0;
}