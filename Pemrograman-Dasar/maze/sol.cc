#include <bits/stdc++.h>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> sum(n, vector<int>(m, -1));
  vector<vector<int>> maze(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> maze[i][j];
    }
  }

  int a, b;
  cin >> a >> b;
  a--;
  b--;

  queue<pair<int, int>> q;
  q.push(make_pair(a, b));
  sum[a][b] = 1;

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    if ((r == 0 || r + 1 == n || c == 0 || c + 1 == m) && maze[r][c] == 0) {
      cout << sum[r][c] << '\n';
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int br = r + dr[i];
      int bc = c + dc[i];

      if (br >= 0 && br < n && bc >= 0 && bc < m && maze[br][bc] == 0 &&
          sum[br][bc] == -1) {
        sum[br][bc] = sum[r][c] + 1;
        q.push(make_pair(br, bc));
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}
