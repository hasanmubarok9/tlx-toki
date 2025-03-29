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
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> k[i] >> d[i];
        if (d[i] == 0) {
            p.push_back(i);
        }
    }

    cout << "nilai p: ";
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i] << " ";
    }
    cout << '\n';

    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= h[i]; --j) {
            cout << "nilai i: " << i << " j: " << j << " dp[j]: " << dp[j] << ",  nilai h[i]: " << h[i] << ", dan nilai j - h[i]: " << j - h[i] << ", dp[j - h[i]]: " << dp[j - h[i]] << " k[i]: " << k[i] << ", dan nilai dp[j - h[i]] + k[i]: " << dp[j - h[i]] + k[i] << '\n';
            dp[j] = max(dp[j], dp[j - h[i]] + k[i]);
            cout << "nilai dp: ";
            for (int k = 0; k <= m; k++) {
                cout << dp[k] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }

    cout << '\n' << '\n';

    cout << "nilai dp: ";
    for (int i = 0; i <= m; ++i) {
        cout << dp[i] << " ";
    }

    cout << '\n' << '\n';

    cout << "nilai p: ";
    for (int i = 0; i < p.size(); ++i) {
        cout << p[i] << " ";
    }
    cout << '\n' << '\n';


    bool changed = true;
    while (changed) {
        changed = false;
        for (int x: p) {
            cout << "nilai x: " << x << '\n';
            for (int j = h[x]; j <= m; ++j) {
                cout << "nilai j: " << j << " dp[j]: " << dp[j] << ",  nilai h[x]: " << h[x] << ", dan nilai j - h[x]: " << j - h[x] << ", dp[j - h[x]]: " << dp[j - h[x]] << " k[x]: " << k[x] << ", dan nilai dp[j - h[x]] + k[x]: " << dp[j - h[x]] + k[x] << '\n';
                if (dp[j] < dp[j - h[x]] + k[x]) {
                    cout << "masuk, ketika nilai dp[j]: " << dp[j] << " < dp[j - h[x]] + k[x]: " << dp[j - h[x]] + k[x] << '\n';
                    dp[j] = dp[j - h[x]] + k[x];
                    changed = true;
                }
                cout << "nilai dp[j] akhir: " << dp[j] << '\n';
                cout << "nilai dp: ";
                for (int k = 0; k <= m; k++) {
                    cout << dp[k] << " ";
                }
                cout << '\n';
            }

        }
        cout << "nilai changed: " << changed << '\n';
    }

    cout << dp[m] << '\n';
    
    return 0;
}
