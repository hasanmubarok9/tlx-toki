#include <bits/stdc++.h>

using namespace std;

const int N = 505, inf = 1e9;

vector<pair<int, bool>> adj[N];

int dist[3][N]; // dist[0] = belum lewat tol, dist[1] = lewat tol

bool vis[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fill(&dist[0][0], &dist[3][0], inf);

    int c, o, t, s, f; // c = city, o = non tol, t = tol, s = start, f = finish

    cin >> c >> o >> t >> s >> f;

    for (int i = 0; i < o; i++) 
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back({y, false});
        adj[y].push_back({x, false});
    }

    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back({y, true});
        adj[y].push_back({x, true});
    }

    queue<pair<int, bool>> q;
    q.push({s, false});
    dist[0][s] = 0;
    dist[1][s] = 0;

    while (!q.empty())
    {
        auto [u, pass] = q.front();
        q.pop();

        if (pass)
        {
            if (dist[0][u] + 1 < dist[1][u])
            {
                dist[1][u] = dist[0][u] + 1;
                q.push({u, true});
            }
        }
        else
        {
            if (dist[0][u] < dist[0][u])
            {
                dist[0][u] = dist[0][u] + 1;
                q.push({u, false});
            }
            if (dist[1][u] < dist[1][u])
            {
                dist[1][u] = dist[1][u] + 1;
                q.push({u, true});
            }
        }                
    }

    cout << min(dist[0][f], dist[1][f]) << '\n';

    return 0;
}
