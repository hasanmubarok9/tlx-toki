#include <bits/stdc++.h>

using namespace std;

struct DSU {
  int n;
  vector<int> p, sz;

  DSU(int n = 0): n(n), p(n), sz(n, 1) {
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return false;
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> cells;
  cells.reserve(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int idx = i * m + j;
      int height;
      cin >> height;
      cells.push_back({ height, idx });
    }
  }

  // sort the cells in decreasing order by the height;
  sort(cells.begin(), cells.end(), [&](auto &a, auto &b) {
      if (a.first != b.first) return a.first > b.first;
      return a.second < b.second;
  });

  DSU dsu(n * m);

  auto id_to_rc = [&] (int idx, int m) {
    return make_pair(idx / m, idx % m);
  };

  int ans = 0, currComponents = 0;
  int i = 0;
  vector<int> active(n * m, 0);
  const int dr[4] = {-1, 0, 1, 0};
  const int dc[4] = {0, 1, 0, -1};
  while (i < cells.size()) {
    int val = cells[i].first;
    int j = i;
    ans = max(ans, currComponents);
    while (j < cells.size() && cells[j].first == val) {
      int idx = cells[j].second;
      active[idx] = 1;
      currComponents++;
      auto [r, c] = id_to_rc(idx, m);
      for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
          continue;
        }
        int nidx = nr * m + nc;
        if (active[nidx]) {
          if (dsu.unite(idx, nidx)) {
            currComponents--;
          }
        }
      }
      j++;
    }
    i = j;
  }
  ans = max(ans, currComponents);

  cout << ans << '\n';

  return 0;
}
