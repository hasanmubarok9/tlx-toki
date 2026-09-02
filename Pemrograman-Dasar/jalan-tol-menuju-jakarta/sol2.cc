#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, T, A, B;
  cin >> N >> M >> T >> A >> B;

  A--;
  B--;

  vector<vector<int>> normals(N); // normal roads
  vector<vector<int>> tolls(N); // toll roads

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    normals[u].push_back(v);
    normals[v].push_back(u);
  }

  for (int i = 0; i < T; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    tolls[x].push_back(y);
    tolls[y].push_back(x);
  }

  queue<pair<int, bool>> q;
  // dist[i][0] = the distance from city A to city i without using toll road
  // dist[i][1] = the distance from city A to city i after passing through the toll road once
  vector<vector<int>> dist(N, vector<int>(2, -1));

  q.push({A, 0});
  dist[A][0] = 0;

  while (!q.empty()) {
    auto [u, used] = q.front();
    q.pop();

    // using normal roads
    for (int v: normals[u]) {
      if (dist[v][used] == -1) {
        dist[v][used] = dist[u][used] + 1;
        q.push({v, used});
      }
    }

    // using toll roads
    if (used == 0) {
      for (int v: tolls[u]) {
        if (dist[v][1] == -1) {
          dist[v][1] = dist[u][0] + 1;
          q.push({v, 1});
        }
      }
    }
  }

  int ans = INT_MAX;

  if (dist[B][0] != -1) {
    ans = min(ans, dist[B][0]);
  }

  if (dist[B][1] != -1) {
    ans = min(ans, dist[B][1]);
  }
  cout << ans << '\n';
  return 0;
}
