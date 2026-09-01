#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int x, vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> dist(n, -1);
  queue<int> q;

  dist[x] = 0;
  q.push(x);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v: graph[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, T, A, B;
  cin >> N >> M >> T >> A >> B;

  A--;
  B--;

  vector<vector<int>> graph(N);
  vector<pair<int, int>> tolls(T);

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 0; i < T; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    tolls[i] = {x, y};
  }

  vector<int> distA, distB;
  distA = bfs(A, graph);
  distB = bfs(B, graph);

  int ans = N;

  if (distA[B] != -1) {
    int ans = distA[B];
  }

  // pass through tolls
  for (auto [x, y]: tolls) {
    if (distA[x] != -1 && distB[y] != -1) {
      ans = min(ans, distA[x] + distB[y] + 1);
    }

    if (distA[y] != -1 && distB[x] != -1) {
      ans = min(ans, distA[y] + distB[x] + 1);
    }
  }
  cout << ans << '\n';
  return 0;
}
