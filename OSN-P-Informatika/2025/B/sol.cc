#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, l, w; // the number of boxes, the length of each box and the width of each box
  cin >> n >> l >> w;

  long long bs = 1, ht = 2e9 + 5; // base and height

  while (bs < ht) {
    int m = (bs + ht) >> 1;

    if ((long long)(m / l) * (long long)(m / w) >= n) {
      ht = m;
    } else {
      bs = m + 1;
    }
  }

  cout << ht << '\n';
  return 0;
}
