#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int p = count(s.begin(), s.end(), 'P');
  int mask = 0;
  int ans = -1, cnt = 0;

  for (char c: s) {
    if (c == 'P') {
      p--;
    } else if (c == 'O' || c == 'S' || c == 'N') {
      cnt++;
      if (c == 'O') {
        mask |= 1;
      } else if (c == 'S') {
        mask |= 2;
      } else {
        mask |= 4;
      }
    }

    if (mask == 7 && p > 0) {
      ans = max(ans, cnt + p);
    }
  }

  cout << ans << '\n';
  return 0;

}
