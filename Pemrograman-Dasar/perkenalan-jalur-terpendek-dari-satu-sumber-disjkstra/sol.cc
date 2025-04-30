#include <bits/stdc++.h>

using namespace std;

const int N = 2505, M = 6205;

int n, m, p, q;
int dist[N];
vector<pair<int, int>> adj[N];
priority_queue<pair<int, int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> p >> q;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    fill(dist, dist + N, 1e9);
    dist[p] = 0;
    pq.emplace(0, p);

    while (!pq.empty())
    {
        auto [du, u] = pq.top();
        // cout << "nilai du: " << du << " nilai u: " << u << '\n';
        pq.pop();
        if (du != dist[u]) continue;
        for (auto [v, w] : adj[u])
        {
            // cout << "nilai du: " << du << " nilai u: " << u << " nilai v: " << v << " nilai w: " << w << '\n';
            if (dist[v] > dist[u] + w)
            {
                cout << "masuk, ketika nilai u: " << u << " nilai v: " << v << " nilai w: " << w << ", nilai dist[u]: " << dist[u] << ", nilai dist[u] + w: " << dist[u] + w << ", nilai dist[v]: " << dist[v] << '\n';
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    cout << "nilai dist: ";
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << '\n';
    cout << dist[q] << '\n';
}
