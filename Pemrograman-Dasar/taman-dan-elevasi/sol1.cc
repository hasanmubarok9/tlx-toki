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

  return 0;
}
