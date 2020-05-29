#include <bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
#define fastio                                                                 \
	ios_base::sync_with_stdio(false);                                          \
	cin.tie(NULL)
#define lld long long int
#define MOD 1000000007

static void print_arr(int arr[], int N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	}

	cout << '\n';
}

int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N, K;
	cin >> N >> K;
	int A[1000000];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	stack<pair<int, int>> st;

	lld ans = 1;

	for (int i = 0; i < N; i++) {
		while ((not st.empty()) and A[i] < st.top().first) {
			auto top = st.top();
			int diff = i - top.second + 1;
			// cout << diff << ' ';
			ans = diff * ans % MOD;
			st.pop();
		}
		st.push({A[i], i});
	}
	// cout << '\n';

	cout << ans << '\n';

	return 0;
=======
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define lld long long int

static void print_arr(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
}

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--) {
    }
    return 0;
>>>>>>> origin/master
}