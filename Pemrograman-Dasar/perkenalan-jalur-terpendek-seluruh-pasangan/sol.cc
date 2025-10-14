#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> d(n, vector<ll>(n, INF));

    for (int i = 0; i < n; i++)
    {
        d[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;

        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int cur, pv;
    cin >> pv;
    pv--;
    q--;
    ll ans = 0;
    while (q--)
    {
        cin >> cur;
        cur--;
        if (d[cur][pv] != INF)
        {
            ans += d[cur][pv];
        }
        pv = cur;
    }

    cout << ans << '\n';
}
