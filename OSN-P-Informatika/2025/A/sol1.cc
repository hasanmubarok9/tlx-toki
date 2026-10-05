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
  cout << "banyaknya p: " << p << endl;

  for (char c: s) {
    cout << "nilai c: " << c << endl;
    if (c == 'P') {
      cout << "masuk p\n";
      p--;
    }
    else if (c == 'O' || c == 'S' || c == 'N') {
      cout << "masuk else, ketika nilai c: " << c << endl;
      cnt++;
      if (c == 'O') mask |= 1;
      if (c == 'S') mask |= 2;
      if (c == 'N') mask |= 4;
      cout << "nilai mask: " << mask << endl;
    }

    cout << "nilai mask: " << mask << ", dan nilai p: " << p << endl;

    if (mask == 7 && p > 0) {
      cout << "ketika nilai mask adalah 7, dan nilai p > 0\n";
      cout << "nilai cnt: " << cnt << ", dan nilai cnt + p: " << (cnt + p) << endl;
      ans = max(ans, cnt + p);
      cout << "nilai ans: " << ans << endl << endl;
    }
  }

  cout << ans << '\n';
}
