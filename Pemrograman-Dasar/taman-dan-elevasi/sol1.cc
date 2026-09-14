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

  vector<int> a(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i * m + j];
    }
  }

  // collect cells (height, index)
  vector<pair<int, int>> cells;
  cells.reserve(n * m);

  for (int idx = 0; idx < n * m; idx++) {
    cells.emplace_back(a[idx], idx);
  }

  // sort descending by height
  sort(cells.begin(), cells.end(), [](auto &A, auto &B) {
      if (A.first != B.first) return A.first > B.first;
      return A.second < B.second;
  });

  cout << "nilai cells setelah diurutkan:\n";
  for (auto [height, idx]: cells) {
    cout << "(" << height << ", " << idx << ")\n";
  }
  cout << '\n';

  DSU dsu(n * m);
  vector<char> active(n * m, 0);
  int currComponents = 0;
  int ans = 0;

  auto id_to_rc = [&](int id) {
    return make_pair(id / m, id % m);
  };

  int i = 0;
  while (i < (int)cells.size()) {
    cout << "di dalam while i, nilai i: " << i << endl;
    int val = cells[i].first;
    cout << "nilai val: " << val << endl;
    // current state correspond to x = val (active = heights > val)
    ans = max(ans, currComponents);
    cout << "nilai ans: " << ans << endl;

    // add all cells with height = val
    int j = i;
    cout << "nilai j: " << j << endl;
    if (j < (int)cells.size()) {
      cout << "nilai cells[j].first: " << cells[j].first << endl;
    }
    cout << endl;
    while (j < (int)cells.size() && cells[j].first == val) {
      cout << "di dalam while j: " << j << "\n";
      int idx = cells[j].second;
      cout << "nilai idx: " << idx << endl;
      active[idx] = 1;
      ++currComponents; // a new component initially
      cout << "nilai componenets initially: " << currComponents << endl;
      auto [r, c] = id_to_rc(idx);
      cout << "nilai r: " << r << ", dan nilai c: " << c << endl;
      // check 4 neighbors
      const int dr[4] = {-1, 1, 0, 0};
      const int dc[4] = {0, 0, -1, 1};
      for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];
        cout << "nilai nr: " << nr << ", dan nilai nc: " << nc << endl;
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        int nidx = nr * m + nc;
        cout << "nilai nidx: " << (nidx) << endl;
        if (active[nidx]) {
          cout << "nidx nya active cuy\n";
          // If they belong to different components, unite and decrease count
          if (dsu.unite(idx, nidx)) {
            --currComponents;
          }
        }
      }
      j++;
    }
    cout << "=======take me to curch\n\n";
    cout << "akhir untuk i: " << i << ", nilai j: " << j << ", dan nilai currComponents: " << (currComponents) << endl << endl;
    i = j;
  }
  // also consider x < min_height (after all cells added)
  ans = max(ans, currComponents);
  cout << ans << '\n';
  return 0;
}
