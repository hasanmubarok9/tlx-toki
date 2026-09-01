#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, T, A, B;
  cin >> N >> M >> T >> A >> B;

  --A;
  --B;

  vector<vector<int>> normal(N);
  vector<vector<int>> toll(N);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    --u;
    --v;

    normal[u].push_back(v);
    normal[v].push_back(u);
  }

  for (int i = 0; i < T; i++) {
    int x, y;
    cin >> x >> y;

    --x;
    --y;
    toll[x].push_back(y);
    toll[y].push_back(x);
  }

  // dist[u][0] = shortest time to u without using a toll
  // dist[u][1] = shortest time to u after using one toll

  vector<vector<int>> dist(N, vector<int>(2, -1));
  queue<pair<int, int>> q;

  dist[A][0] = 0;
  q.push({A, 0});

  while (!q.empty()) {
    auto [u, used] = q.front();
    q.pop();

    // Use normal road
    for (int v: normal[u]) {
      if (dist[v][used] == -1) {
        dist[v][used] = dist[u][used] + 1;
        q.push({v, used});
      }
    }

    // Use toll, only if we haven't used one yet
    if (used == 0) {
      for (int v: toll[u]) {
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
