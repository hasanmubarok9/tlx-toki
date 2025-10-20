#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;
const int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
const int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m, k, s, qi, qj;
    cin >> n >> m >> k >> s >> qi >> qj;

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int> (m, INF));

    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      dist[x][y] = 0;
      q.emplace(x, y);
    }

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      if (dist[x][y] == s) continue;

      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (dist[nx][ny] > dist[x][y] + 1) {
          dist[nx][ny] = dist[x][y] + 1;
          q.emplace(nx, ny);
        }
      }
    }

    if (dist[qi - 1][qj - 1] <= s) {
      cout << "TRUE\n";
    } else {
      cout << "FALSE\n";
    }
  }
}
