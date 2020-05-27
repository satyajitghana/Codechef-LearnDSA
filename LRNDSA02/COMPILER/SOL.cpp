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
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        stack<char> st;
        int score = 0;
        int pops = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '<')
                st.push('<');

            else if (st.empty())
                break;

            else if (st.top() == '<') {
                st.pop();
                pops++;

                if (st.empty()) {
                    score += pops * 2;
                    pops = 0;
                }
            }
        }

        cout << score << '\n';
    }
    return 0;
}