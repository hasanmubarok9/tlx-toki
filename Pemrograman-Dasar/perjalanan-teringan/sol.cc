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
      cout << "nilai i: " << i << ", nilai j: " << j << ", nilai i * C + j: " << i * C + j << ", nilai x: " << x << endl;
      A[i * C + j] = x;
    }
  }
  cout << "nilai A: ";
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << A[i * C + j] << " ";
    }
    cout << " ### ";
  }
  cout << endl;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  b--;
  c--;
  d--;
  cout << "nilai a: " << a << ", nilai b: " << b << ", nilai c: " << c << ", nilai d: " << d << endl;
  int s = a * C + b;
  int t = c * C + d;
  cout << "nilai s: " << s << ", nilai t: " << t << endl;

  // if end is blocked -> unreachable
  if (A[t] == -1) {
    cout << -1 << endl;
    return 0;
  }

  if (s == t) {
    cout << A[t] << endl;
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
    cout << "di dalam while, BFS!!!, nilai cost: " << cost << ", nilai u: " << u << endl;
    pq.pop();

    if (cost != dist[u])
      continue;
    if (u == t)
      break; // reached with minimal bottleneck
    int ux = u / C;
    int uy = u % C;
    cout << "nilai ux: " << ux << ", nilai uy: " << uy << endl;
    for (int k = 0; k < 4; k++) {
      int nx = ux + dx[k];
      int ny = uy + dy[k];
      cout << "nilai nx: " << nx << ", nilai ny: " << ny << endl;
      if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        continue;
      int v = nx * C + ny;
      cout << "nilai v: " << v << ", dan nilai A[v]: " << A[v] << endl;
      if (A[v] == -1)
        continue;
      cout << "nilai v: " << v << ", dan nilai A[v]: " << A[v] << endl;
      int ncost = max(cost, A[v]);
      cout << "nilai ncost: " << ncost << endl;
      if (ncost < dist[v]) {
        cout << "massukk ncost " << ncost << endl;
        dist[v] = ncost;
        pq.push({ncost, v});
      }
    }
    cout << "akhir while, untuk cost: " << cost << ", u: " << u << endl << endl;
  }

  if (dist[t] == INF)
    cout << -1 << '\n';
  else
    cout << dist[t] << '\n';
  return 0;
}
