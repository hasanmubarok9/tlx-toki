#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  int dx = x1 - x2;
  int dy = y1 - y2;

  int d2 = (dx * dx) + (dy * dy);

  int sum = r1 + r2;
  int diff = abs(r1 - r2);
  int sum2 = sum * sum;
  int diff2 = diff * diff;

  if (diff2 <= d2 && d2 <= sum2) {
    cout << "bersentuhan\n";
  } else {
    cout << "tidak bersentuhan\n";
  }

  return 0;
}
