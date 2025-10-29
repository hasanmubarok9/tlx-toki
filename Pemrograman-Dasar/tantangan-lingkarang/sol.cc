#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

  cout << "nilai x1: " << x1 << ", nilai y1: " << y1 << ", nilai r1: " << r1 << ", nilai x2: " << x2 << ", nilai y2: " << y2 << ", dan nilai r2: " << r2 << endl;

  int dx = x1 - x2;
  int dy = y1 - y2;

  cout << "nilai dx: " << dx << ", dan nilai dy: " << dy << endl;

  int d2 = (dx * dx) + (dy * dy);
  cout << "nilai d2: " << d2 << endl;

  int sum = r1 + r2;
  cout << "nilai sum: " << sum << endl;
  int diff = abs(r1 - r2);
  cout << "nilai diff: " << diff << endl;
  int sum2 = sum * sum;
  cout << "nilai sum2: " << sum2 << endl;
  int diff2 = diff * diff;
  cout << "nilai diff2: " << diff2 << endl;

  if (diff2 <= d2 && d2 <= sum2) {
    cout << "masukk, nilai diff2: " << diff2 << ", nilai d2: " << d2 << ", dan nilai sum2: " << sum2 << endl;
    cout << "bersentuhan\n";
  } else {
    cout << "tidak bersentuhan\n";
  }

  return 0;
}
