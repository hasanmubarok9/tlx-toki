#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<long long> s(n + 1);
  s[0] = 0;
  s[1] = a[1];
  for (int i = 2; i <= n; i++) {
    s[i] = s[i - 1] + a[i];
  }

  cout << "nilai s: ";
  for (int i = 0; i <= n; i++) {
    cout << s[i] << ' ';
  }
  cout << endl;

  int q;
  cin >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << s[r] - s[l - 1] << '\n';
  }
}
