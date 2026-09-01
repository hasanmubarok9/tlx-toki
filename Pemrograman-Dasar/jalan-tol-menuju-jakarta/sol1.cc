#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int start, const vector<vector<int>>& graph) {
  int n = graph.size();
  vector<int> dist(n, -1);
  queue<int> q;

  dist[start] = 0;
  q.push(start);

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

  --A;
  --B;

  vector<vector<int>> graph(N);
  vector<pair<int, int>> tolls(T);

  // Jalan Biasa
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;

    --u; --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  // Jalan Tol
  for (int i = 0; i < T; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    tolls[i] = {x, y};
  }

  // Jarak menggunakan jalan biasa
  vector<int> distA = bfs(A, graph);
  vector<int> distB = bfs(B, graph);


  // Tidak menggunakan tol
  int ans = distA[B];


  // Gunakan tepat satu jalan tol
  for (auto [x, y]: tolls) {
    if (distA[x] != -1 && distB[y] != -1) {
      ans = min(ans, distA[x] + 1 + distB[y]);
    }
    if (distA[y] != -1 && distB[x] != -1) {
      ans = min(ans, distA[y] + 1 + distB[x]);
    }
  }

  cout << ans << '\n';
  return 0;
}
