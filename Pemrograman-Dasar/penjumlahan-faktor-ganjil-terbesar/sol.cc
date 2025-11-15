#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  /*
  // TIME LIMIT EXCEED
  long long ans = 0;

  for (int i = 1; i <= n; i++) {
    int ctz = __builtin_ctz(i);
    ans += (i >> ctz);
  }
  cout << ans << '\n';
  */

  long long ans = 0;
  while (n > 0) {
    long long m = (n + 1) >> 1; // number of odd numbers <= n
    ans += m * m;               // sum of first m odd numbers = m ^ 2
    n /= 2;                     // handle even part
  }

  cout << ans << '\n';
  return 0;
}
