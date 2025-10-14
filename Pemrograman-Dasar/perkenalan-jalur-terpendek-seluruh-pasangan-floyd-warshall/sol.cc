#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
int adj[201][201], dist[201][201];

void solve()
{
    memset(adj, 0, sizeof(adj));
    int n, m, q;
    cin >> n >> m >> q;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = (adj[u][v] ? min(adj[u][v], w) : w);
        adj[v][u] = (adj[v][u] ? min(adj[v][u], w) : w);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else if (adj[i][j])
            {
                dist[i][j] = adj[i][j];
            }
            else
            {
                dist[i][j] = INF;
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    vector<int> house(q);
    for (int i = 0; i < q; i++)
    {
        cin >> house[i];
    }
    int ans = 0;
    for (int i = 0; i < q - 1; i++)
    {
        ans += dist[house[i]][house[i + 1]];
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
