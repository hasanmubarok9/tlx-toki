#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll MOD = 26101991;

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
  for (int len = 2; len <= N; len++) {
    for (int i = 0; i + len - 1 < N; i++) {
      int j = i + len - 1;

      dp[i][j] = LLONG_MAX;
      ways[i][j] = 0;
      all[i][j] = 0;

      for (int k = i; k < j; k++) {
        // Cost of splitting
        // (M[i] ... M[k]) * (M[k + 1] ... M[j])
        ll cost = dp[i][k] + dp[k + 1][j] + A[i] * A[k + 1] * A[j + 1];

        // Count ALL possible ways
        all[i][j] = (all[i][j] + all[i][k] * all[k + 1][j]) % MOD;

        // Count minimum-cost ways
        ll currentWays = (ways[i][k]* ways[i + 1][j]) % MOD;

        if (cost < dp[i][j]) {
          dp[i][j] = cost;
          ways[i][j] = currentWays;
        } else if (cost == dp[i][j]) {
          ways[i][j] += currentWays;
          ways[i][j] %= MOD;
        }
      }
    }
  }

  if (Q == 1) {
    cout << dp[0][N - 1] << '\n';
  } else if (Q == 2) {
    cout << ways[0][N - 1] << '\n';
  } else {
    cout << all[0][N - 1] << '\n';
  }

  return 0;
}
