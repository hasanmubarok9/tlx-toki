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
  cout << "nilai k: ";
  for (int i = 0; i < m; i++) {
    cout << k[i] << ' ';
  }
  cout << endl;

  for (long long i = m; i > 0; i--) {
    cout << "nilai i: " << i << ", nilai i + 1: " << i + 1
         << ", nilai pr[i + 1]: " << pr[i + 1] << ", dan nilai costr: " << costr
         << endl;
    pr[i] = pr[i + 1] + costr;
    cout << "nilai k[i]: " << k[i] << endl;
    if (k[i] == 1)
      costr++;
    cout << "nilai akhir, costr: " << costr << endl << endl;
  }

  long long pl = 0;
  for (long long i = 1; i <= m; i++) {
    cout << "nilai i: " << i << ",  nilai pl: " << pl
         << ", dan nilai costl: " << costl << endl;
    pl = pl + costl;
    cout << "nilai pl yang baru: " << pl << endl;

    if (k[i] == 1)
      costl++;

    cout << "nilai costl yang baru: " << costl
         << ", nilai pl + pr[i]: " << (pl + pr[i]) << ", nnnilai bval: " << bval
         << ", dan nilai k[i]: " << k[i] << endl;
    if (pl + pr[i] > bval && k[i] == 0) {
      cout << "masuk attack on titan\n";
      bval = pl + pr[i];
      ans = i;
    }
    cout << "akhir untuk i: " << i << ", nilai ans: " << ans << endl << endl;
  }
  cout << ans << '\n';
}
