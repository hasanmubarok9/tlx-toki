#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<ll> A(N + 1);
  for (int i = 0; i <= N; i++) {
    cin >> A[i];
  }

  int Q;
  cin >> Q;

  // dp[i][j] = minimum cost for M[i] ... M[j]
  vector<vector<ll>> dp(N, vector<ll>(N, 0));

  // ways[i][j] = number of minimum-cost ways
  vector<vector<ll>> ways(N, vector<ll>(N, 0));

  // all[i][j] = number of all possible parenthesizations
  vector<vector<ll>> all(N, vector<ll>(N, 0));

  for (int i = 0; i < N; i++) {
    ways[i][i] = 1;
    all[i][i] = 1;
  }

  // len = number of matrices in the interval
}
