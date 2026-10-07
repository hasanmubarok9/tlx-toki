#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  // int mv = 1e18, mk = -1;
  int mv = 100, mk = -1;
  for (int i = 2; i * i <= n; i++) {
    cout << "nilai i: " << i << endl;
    if (n % i > 0) continue;
    int p = 0;
    while (n % i == 0) {
      cout << "di dalam while, nilai n: " << n << ", dan nilai i: " << i << endl;
      p += 1;
      n /= i;
      cout << "akhir while, nilai p: " << p << ", dan nilai n: " << n << endl;
    }
    cout << "setelah while, nilai p: " << p << ", dan nilai mv: " << mv << endl;
    if (p < mv) {
      mv = p;
      mk = i;
    }
    cout << "akhir untuk i: " << i << endl << endl;
  }

  cout << "nilai n: " << ", dan nilai mv: " << mv << endl;
  if (n > 1 && mv > 1) {
    mk = n;
  }
  cout << mk << '\n';
  return 0;
}
