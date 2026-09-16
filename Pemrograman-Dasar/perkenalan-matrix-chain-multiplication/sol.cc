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
    cout << "nilai len: " << len << endl;
    for (int i = 0; i + len - 1 < N; i++) {
      cout << "nilai i: " << i << endl;
      int j = i + len - 1;
      cout << "nilai j: " << j << endl;

      dp[i][j] = LLONG_MAX;
      ways[i][j] = 0;
      all[i][j] = 0;

      for (int k = i; k < j; k++) {
        cout << "nilai k: " << k << endl;
        cout << "nilai dp[i][k]: " << dp[i][k] << endl;
        cout << "nilai dp[k + 1][j]: " << dp[k + 1][j] << endl;
        cout << "nilai A[i]: " << A[i] << endl;
        cout << "nilai A[k + 1]: " << A[k + 1] << endl;
        cout << "nilai A[j + 1]: " << A[j + 1] << endl;
        // Cost of splitting
        // (M[i] ... M[k]) * (M[k + 1] ... M[j])
        ll cost = dp[i][k] + dp[k + 1][j] + A[i] * A[k + 1] * A[j + 1];
        cout << "nilai cost: " << cost << endl;

        // Count ALL possible ways
        cout << "nilai all[i][j]: " << all[i][j] << endl;
        cout << "nilai all[i][k]: " << all[i][k] << endl;
        cout << "nilai all[k + 1][j]: " << all[k + 1][j] << endl;
        all[i][j] = (all[i][j] + all[i][k] * all[k + 1][j]) % MOD;
        cout << "nilai yang baru dari all[i][j]: " << all[i][j] << endl;

        // Count minimum-cost ways
        ll currentWays = (ways[i][k]* ways[i + 1][j]) % MOD;
        cout << "nilai currentWays: " << currentWays << endl;
        cout << "nilai cost: " << cost << ", dan nilai dp[i][j]: " << dp[i][j] << endl;

        if (cost < dp[i][j]) {
          dp[i][j] = cost;
          ways[i][j] = currentWays;
        } else if (cost == dp[i][j]) {
          ways[i][j] += currentWays;
          ways[i][j] %= MOD;
        }
      }
      cout << "nilai i: " << i << endl;
    }
    cout << "akhir untuk len: " << len << endl << endl;
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
