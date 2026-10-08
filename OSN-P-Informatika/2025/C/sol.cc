#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  long long mv = 1e18; // minimum value found so far
  int mk = -1; // prime corresponding to that minimum value
  for (int i = 2; i * i <= n; i++) { // i is the candidate prime factor
    cout << "nilai i: " << i << endl << endl;
    if (n % i > 0) continue;
    int p = 0;
    while (n % i == 0) {
      cout << "di dalam while, nilai n: " << n << ", dan nilai i: " << i << endl;
      p += 1;
      n /= i;
      cout << "akhir while, nilai p: " << p << ", dan nilai n: " << n << endl;
    }
    cout << "setelah while, nilai p: " << p << ", nilai mv: " << mv << ", dan nilai mk: " << mk << endl << endl;
    if (p < mv) { // if the prime's exponent is smaller than the best exponent found so far, make this prime the answer
      mv = p;
      mk = i;
    }
    cout << "akhir untuk i, nilai mv: " << mv << ", dan nilai mk: " << mk << endl;
    cout << "akhir untuk i: " << i << endl << endl;
  }

  cout << "nilai n: " << n << ", dan nilai mv: " << mv << endl;
  if (n > 1 && mv > 1) {
    mk = n;
  }
  cout << mk << '\n';
  return 0;
}
