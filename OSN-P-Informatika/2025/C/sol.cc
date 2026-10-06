#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int mv = 1e18, mk = -1;
  for (int i = 2; i * i <= n; i++) {
    if (n % i > 0) continue;
    int p = 0;
    while (n % i == 0) {
      p += 1;
      n /= i;
    }
    if (p < mv) {
      mv = p;
      mk = i;
    }
  }
  if (n > 1 && mv > 1) {
    mk = n;
  }
  cout << mk << '\n';
  return 0;
}
