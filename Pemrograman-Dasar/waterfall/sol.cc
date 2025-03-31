#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int v, h, n;
    cin >> v >> h >> n;

    v++;
    bool arr[v][h];
    memset(arr, 0, sizeof(arr));

    while (n--)
    {
        int v1, h1, v2, h2;
        cin >> v1 >> h1 >> v2 >> h2;

        for (int i = v1; i <= v2; i++)
        {
            for (int j = h1; j <= h2; j++)
            {
                arr[i][j - 1] = 1;
            }
        }
    }

    ll dp[v][h];
    for (int i = 0; i < h; i++) {
        dp[v - 1][i] = 0;
    }
    for (int i = v - 2; i > 0; i--) {
        for (int j = 0; j < h; j++) {
            if (arr[i][j]) continue;
            if (!arr[i + 1][j]) dp[i][j] = dp[i + 1][j];
            else {
                int l = j, r = j;
                while (l >= 0 && arr[i + 1][l]) l--;
                while (r < h && arr[i + 1][r]) r++;

                ll cntl, cntr;

                if (l < 0) cntl = 0;
                else cntl = dp[i + 1][l];

                if (r == h) cntr = 0;
                else cntr = dp[i + 1][r];

                dp[i][j] = 1 + cntl + cntr;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < h; i++) {
        ans = max(ans, dp[0][i]);
    }

    cout << ans << '\n';
}