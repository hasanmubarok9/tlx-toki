#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  char k[m + 5];
  memset(k, 0, sizeof(k));

  vector<long long> pr(m + 5, 0);
  long long costl = 0, costr = 0;
  long long bval = 0, ans = -1;
  for (int i = 1; i <= n; i++) {
    long long b;
    cin >> b;

    if (b >= 1 && b <= m) {
      k[b] = 1;
    }
  }

  for (long long i = m; i > 0; i--) {
    pr[i] = pr[i + 1] + costr;
    if (k[i] == 1)
      costr++;
  }

  long long pl = 0;
  for (long long i = 1; i <= m; i++) {
    pl = pl + costl;

    if (k[i] == 1)
      costl++;
    if (pl + pr[i] > bval && k[i] == 0) {
      bval = pl + pr[i];
      ans = i;
    }
  }
  cout << ans << '\n';
}
