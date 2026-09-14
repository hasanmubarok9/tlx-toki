#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int n = s.size();
  int idx = 0, inc = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (idx < n) cout << s[idx];
      else cout << '.';
      idx += inc;
    }
    if (inc == 1) idx += (n - 1);
    else idx += n + 1;
    inc *= -1;
    cout << '\n';
  }
  return 0;
}
