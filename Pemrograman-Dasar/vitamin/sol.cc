#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> h(n), k(n), d(n);

    vector<int> p;
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> k[i] >> d[i];
        if (d[i] == 0) {
            p.push_back(i);
        }
    }

    vector<int> dp(m + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = m; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j - h[i]] + k[i]);
        }
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (int x: p) {
            for (int j = h[x]; j <= m; j++) {
                if (dp[j] < dp[j - h[x]] + k[x]) {
                    dp[j] = dp[j - h[x]] + k[x];
                    changed = true;
                }
            }
        }
    }

    cout << dp[m] << '\n';
    return 0;
}
