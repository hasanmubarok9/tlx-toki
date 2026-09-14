#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int slen = s.size();
  int n = ceil(sqrtl(slen));
  int idx = 0, inc =  1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (idx < slen) cout << s[idx];
      else cout << '.';
      idx += inc;
    }
    cout << '\n';
    if (inc == 1) idx += (n - 1);
    else idx += n + 1;
    inc *= -1;
  }
  return 0;
}
