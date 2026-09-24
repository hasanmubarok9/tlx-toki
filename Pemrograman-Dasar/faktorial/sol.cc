#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int res = 0;

  while (n > 0) {
    res += n / 5;
    n /= 5;
  }

  cout << res << '\n';
}
