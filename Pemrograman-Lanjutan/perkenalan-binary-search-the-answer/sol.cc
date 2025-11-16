#include <bits/stdc++.h>

using namespace std;

using ll = long double;

const ll MOD = 998244353;
const ll EPS = 1e-6;

ll N, M;

double a[50005];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  double l = 0;
  // double r = 2e9;
  double r = 5;
  double ans = r;

  while (r - l >= EPS) {
    cout << "nilai r: " << r << ", dan nilai l: " << l
         << ", nilai r - l: " << r - l << '\n';
    double m = (l + r) / 2;
    cout << "nilai m: " << m << '\n';
    ll sum = 0;
    for (int j = 1; j <= N; j++) {
      cout << "nilai j: " << j << ", nilai a[j]: " << a[j]
           << ", dan nilai ceil(a[j] / m): " << ceil(a[j] / m) << '\n';
      sum += ceil(a[j] / m);
      cout << "nilai sum: " << sum << '\n';
    }
    cout << "nilai sum: " << sum << '\n';
    if (sum <= M) {
      cout << "masuk if\n";
      ans = m;
      r = m;
    } else {
      cout << "masuk else\n";
      l = m;
    }
    cout << "nilai ans: " << ans << ", nilai l: " << l << ", dan nilai r: " << r
         << '\n';

    if (abs(r - l) < EPS) {
      break;
    }
  }

  cout << fixed << setprecision(2) << ans << '\n';
}
