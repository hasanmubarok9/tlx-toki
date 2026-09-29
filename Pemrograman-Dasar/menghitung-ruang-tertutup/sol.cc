#include <bits/stdc++.h>

using namespace std;

const int N = 760;

bool grid[N][N];
bool visited[N][N];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void floodfill(int rstart, int cstart, int maxr, int maxc) {
  queue<pair<int, int>> q;

  q.push({rstart, cstart});
  visited[rstart][cstart] = true;

  while (!q.empty()) {
    auto [r, c] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (nr >= 0 && nr <= maxr && nc >= 0 && nc <= maxc) {
        if (!grid[nr][nc] && !visited[nr][nc]) {
          visited[nr][nc] = true;
          q.push({nr, nc});
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int nn = 3 * n + 1;
  int nm = 3 * m + 1;

  for (int i = 0; i < n; i++) {
    string sr;
    cin >> sr;

    for (int j = 0; j < m; j++) {
      int br = 1 + i * 3;
      int bc = 1 + j * 3;

      if (sr[j] == '/') {
        grid[br][bc + 2] = true;
        grid[br + 1][bc + 1] = true;
        grid[br + 2][bc] = true;
      } else if (sr[j] == '\\') {
        grid[br][bc] = true;
        grid[br + 1][bc + 1] = true;
        grid[br + 2][bc + 2] = true;
      }
    }
  }

  floodfill(0, 0, nn, nm);

  int nroom = 0;
  for (int i = 1; i <= 3 * n; i++) {
    for (int j = 1; j <= 3 * m; j++) {
      if (!grid[i][j] && !visited[i][j]) {
        nroom++;
        floodfill(i, j, nn, nm);
      }
    }
  }

  cout << nroom << '\n';
  return 0;
}
