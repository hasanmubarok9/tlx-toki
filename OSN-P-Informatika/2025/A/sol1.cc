#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int ans = -1, cnt = 0;
  int p = count(s.begin(), s.end(), 'P');
  int mask = 0;

  for (char c: s) {
    if (c == 'P') p--;
    else if (c == 'O' || c == 'S' || c == 'N') {
      cnt++;
      if (c == 'O') mask |= 1;
      if (c == 'S') mask |= 2;
      if (c == 'N') mask |= 4;
    }

    if (mask == 7 && p > 0) {
      ans = max(ans, cnt + p);
    }
  }

  cout << ans << '\n';
}
