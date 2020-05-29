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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    auto prec = [&](char c) {
        switch (c) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;

            default:
                return -1;
        }
    };

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string infix;
        cin >> infix;

        stack<char> op;

        for (auto ch : infix) {
            if (ch >= 'A' and ch <= 'Z')
                cout << ch;

            else if (ch == '(')
                op.push('(');

            else if (ch == ')') {
                while ((not op.empty()) and op.top() != '(') {
                    cout << op.top();
                    op.pop();
                }

                if (op.top() == '(')
                    op.pop();
            }

            else {
                // another op was added, so pop the higher priority ones

                while ((not op.empty()) and prec(op.top()) >= prec(ch)) {
                    cout << op.top();
                    op.pop();
                }

                op.push(ch);
            }
        }
        // parse the remaining ops in the stack
        while (not op.empty()) {
            if (op.top() != '(')
                cout << op.top();
            op.pop();
        }
        cout << '\n';
    }
    return 0;
}