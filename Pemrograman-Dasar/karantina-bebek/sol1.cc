#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> k(n);
  vector<bool> occupied(m + 1, false);

  for (int i = 0; i < n; i++) {
    cin >> k[i];
    occupied[k[i]] = true;
  }

  // Cari kandang kosong paling kecil
  int l = -1;
  for (int i = 1; i <= m; i++) {
    if (!occupied[i]) {
      l = i;
      break;
    }
  }

  // Semua kandang penuh
  if (l == -1) {
    cout << -1 << '\n';
    return 0;
  }

  // Cari kandang kosong paling besar
  int r = -1;
  for (int i = m; i >= 1; i--) {
    if (!occupied[i]) {
      r = i;
      break;
    }
  }

  // Hitung total jarak untuk l dan r
  long long dist_l = 0;
  long long dist_r = 0;

  for (int x: k) {
    dist_l += abs(l - x);
    dist_r += abs(r - x);
  }

  if (dist_l >= dist_r) {
    // >= supaya saat sama, pilih nomor lebih kecil (L)
    cout << l << '\n';
  } else {
    cout << r << '\n';
  }

  return 0;
}
