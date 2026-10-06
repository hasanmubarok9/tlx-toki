#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, l, w; // the number of box, the length of the box, and the width of the box
  cin >> n >> l >> w;

  // int bs = 1, ht = 2e9 + 5; // base and height;
  int bs = 1, ht = 100; // debugging

  // binary search
  while (bs < ht) {
    cout << "nilai bs: " << bs << ", dan nilai ht: " << ht << endl << "\n";
    int m = (bs + ht) >> 1;
    cout << "nilai m: " << m << endl;
    cout << "nilai m / l: " << (m / l) << ", nilai m / w: " << (m / w) << ", dan nilai (m / l) * (m / w): " << (m / l) * (m / w) << endl;
    if ((long long)(m / l) * (long long)(m / w) >= n) {
      ht = m;
    } else {
      bs = m + 1;
    }
    cout << "akhir while, nilai ht: " << ht << ", dan nilai bs: " << bs << endl << endl;
  }
  cout << ht << '\n';
}
