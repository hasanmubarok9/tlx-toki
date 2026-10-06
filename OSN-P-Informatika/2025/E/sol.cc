#include <bits/stdc++.h>

using namespace std;

const int INF = 1e15;

int n, m, k;
int t[800005];

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) t[v] = val;
  else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm) update(2 * v, tl, tm, pos, val);
    else update(2 * v + 1, tm + 1, tr, pos, val);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r) return -INF;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) >> 1;
  return max(query(2 * v, tl, tm, l, min(r, tm)), query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m >> k;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);

  for (int i = 0; i <= 4 * n; i++) {
    t[i] -= INF;
  }

  update(1, 0, n, 0, 0);

  int p = 0;

  for (int i = 1; i <= n; i++) {
    while (a[i - 1] - a[p] > k) p++;

    int best = query(1, 0, n, p, i - m);

    if (best != -INF) {
      update(1, 0, n, i, best + 1);
    }
  }

  int res = query(1, 0, n, n, n);
  cout << (res < 0 ? -1 : res) << '\n';

  return 0;
}
