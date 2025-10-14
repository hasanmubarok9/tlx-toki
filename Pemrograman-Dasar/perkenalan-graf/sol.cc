#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m, k;
vector<int> adj[N];
bool vis[N];

void dfs(int u)
{
    vis[u] = true;
    for (auto v: adj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            k++;
        }
    }

    cout << k << '\n';
    
    return 0;
}
