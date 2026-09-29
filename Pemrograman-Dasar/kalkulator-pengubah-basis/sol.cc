#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long b;
  cin >> b;

  string s;
  cin >> s;

  int n = s.size();

  vector<int> dp(n + 1, 0);

  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    if (dp[i] == 0) continue;
    // case 1
    // substring started with '0'
    if (s[i] == '0') {
      dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    } else {
      long long val = 0;
      for (int j = i; j < n; j++) {
        val = val * 10 + (s[j] - '0');
        if (val >= b) {
          break;
        }
        dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}
