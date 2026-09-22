#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long b;
  string s;

  cin >> b >> s;

  int n = s.size();

  // dp[i] stores the number of ways to truncate s[0...i - 1]
  vector<int> dp(n + 1, 0);
  dp[0] = 1; // base case

  for (int i = 0; i < n; i++) {
    cout << "nilai i: " << i << ", dan nilai dp[i]: " << dp[i] << endl;
    if (dp[i] == 0) continue; // if position i cannot be reached, skip it

    // case 1: substring started with '0'
    if (s[i] == '0') {
      cout << "case 1, substring started with '0'\n";
      cout << "nilai dp[i]: " << dp[i] << ", dan nilai dp[i + 1]: " << dp[i + 1] << endl;
      // '0' can only stand alone as the digit 0
      if (0 < b) {
        dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
      }
    }

    // case 2: substring started with digit '1' - '9'
    else {
      long long val = 0;
      for (int j = i; j < n; j++) {
        cout << "nilai j: " << j << ", dan nilai s[j]: " << s[j] << ", dan nilai val: " << val << endl;;
        val = val * 10 + (s[j] - '0');
        cout << "nilai val baru: " << val << endl;

        // If the substring value exceeds or is equal to b, then
        // the longer truncation is definitely invalid (break)
        if (val >= b) {
          break;
        }

        // If valid (val < b), add probability to dp[j + 1]
        dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
      }
    }

    cout << "akhir untuk i: " << i << ", nilai dp: ";
    for (int k = 0; k <= n; k++) {
      cout << dp[k] << ' ';
    }
    cout << '\n' << '\n';
  }

  cout << "nilai dp akhir: ";
  for (int i = 0; i < n + 1; i++) {
    cout << dp[i] << ' ';
  }
  cout << '\n';

  // The final result is dp[n]
  cout << dp[n] << '\n';
  return 0;
}
