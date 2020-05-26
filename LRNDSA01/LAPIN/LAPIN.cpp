#include <bits/stdc++.h>

using namespace std;

int main() {

  int T;
  cin >> T;

  while (T--) {
    string str;
    cin >> str;
    auto len = str.length();
    auto first_half = str.substr(0, len / 2);
    auto second_half = str.substr((len / 2) + (len % 2 == 0 ? 0 : 1));

    map<char, int> cnt;

    for (auto ch : first_half)
      cnt[ch]++;

    for (auto ch : second_half)
      cnt[ch]--;

    bool lapin = true;
    for (const auto &val : cnt) {
      if (val.second != 0) {
        lapin = false;
        break;
      }
    }

    lapin ? cout << "YES" : cout << "NO";

    cout << '\n';
  }

  return 0;
}