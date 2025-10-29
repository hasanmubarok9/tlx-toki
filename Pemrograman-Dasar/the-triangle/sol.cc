#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long a, b, c;
  cin >> a >> b >> c;

  // sort the sides
  long long x = min({a, b, c});
  long long z = max({a, b, c});
  long long y = a + b + c - x - z;

  cout << (x + y <= z ? z - (x + y) + 1 : 0) << '\n';
}
