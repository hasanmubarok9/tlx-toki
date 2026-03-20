#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n * m);
  for (int i = 0; i < n * m; i++) {
    cin >> a[i];
  }

  int sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  sx--;
  sy--;
  ex--;
  ey--;

  int start = sx * m + sy;
  int end = ex * m + ey;

  // if start point is blocked, return 0
  if (a[start] == -1) {
    cout << -1 << '\n';
    return 0;
  }

  // if end point is unreachable, return 0
  if (a[end] == -1) {
    cout << -1 << '\n';
    return 0;
  }

  // if end point is same as start point, return the value of start point
  if (start == end) {
    cout << a[start] << '\n';
    return 0;
  }

  vector<int> dist(n * m, INT_MAX);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[start] = a[start];
  // start distance is 0 because start not counted
  pq.push({0, start});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (d > dist[u]) {
      continue;
    }

    int ux = u / m;
    int uy = u % m;
    for (int i = 0; i < 4; i++) {
      int vx = ux + dx[i];
      int vy = uy + dy[i];
      if (vx < 0 || vx >= n || vy < 0 || vy >= m) {
        continue;
      }
      int v = vx * m + vy;
      if (a[v] == -1) {
        continue;
      }

      int nd = max(d, a[v]);
      if (nd < dist[v]) {
        dist[v] = nd;
        pq.push({nd, v});
      }
    }
  }

  if (dist[end] == INT_MAX) {
    cout << -1 << '\n';
  } else {
    cout << dist[end] << '\n';
  }
  return 0;
}