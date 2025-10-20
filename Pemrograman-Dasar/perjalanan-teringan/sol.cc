#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int INF = 1e9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int R, C;
  cin >> R >> C;

  vector<int> A(R * C);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int x;
      cin >> x;
      A[i * C + j] = x;
    }
  }
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  b--;
  c--;
  d--;
  int s = a * C + b;
  int t = c * C + d;

  // if end is blocked -> unreachable
  if (A[t] == -1) {
    cout << -1 << endl;
    return 0;
  }

  if (s == t) {
    cout << a[t] << endl;
    return 0;
  }

  vector<int> dist(R * C, INF);
  // If start cell is -1 -> cannot start
  if (A[s] == -1) {
    cout << -1 << endl;
    return 0;
  }

  // start cost = 0 because start not counted
  dist[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});

  while (!pq.empty()) {
    auto [cost, u] = pq.top();
    pq.pop();

    if (cost != dist[u])
      continue;
    if (u == t)
      break; // reached with minimal bottleneck
    int ux = u / C;
    int uy = u % C;
    for (int k = 0; k < 4; k++) {
      int nx = ux + dx[k];
      int ny = uy + dy[k];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        continue;
      int v = nx * C + ny;
      if (A[v] == -1)
        continue;
      int ncost = max(cost, A[v]);
      if (ncost < dist[v]) {
        dist[v] = ncost;
        pq.push({ncost, v});
      }
    }
  }

  if (dist[t] == INF)
    cout << -1 << '\n';
  else
    cout << dist[t] << '\n';
  return 0;
}
