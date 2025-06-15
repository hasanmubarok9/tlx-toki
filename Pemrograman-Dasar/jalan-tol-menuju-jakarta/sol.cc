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

    cout << "nilai adj:\n";
    for (int i = 1; i <= c; i++)
    {
        cout << i << ": ";
        for (auto j : adj[i]) cout << j.first << " ";
        cout << '\n';
    }

    queue<pair<int, bool>> q;
    q.push({s, false});
    dist[0][s] = 0;
    dist[1][s] = 0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (auto next : adj[cur.first])
        {
            if (cur.second && next.second) continue;
            bool tol = next.second;
            if (tol)
            {
                if (dist[0][cur.first] + 1 < dist[1][next.first])
                {
                    dist[1][next.first] = dist[0][cur.first] + 1;
                    q.push({next.first, true});
                }
            }
            else
            {
                if (dist[0][cur.first] < dist[0][next.first])
                {
                    dist[0][next.first] = dist[0][cur.first] + 1;
                    q.push({next.first, false});
                }
                if (dist[1][cur.first] < dist[1][next.first])
                {
                    dist[1][next.first] = dist[1][cur.first] + 1;
                    q.push({next.first, true});
                }
            }
        }

        cout << "akhir while, nilai q:\n";
        auto temp = q;
        while (!temp.empty())
        {
            cout << temp.front().first << " " << temp.front().second << '\n';
            temp.pop();
        }
    }

    cout << min(dist[0][f], dist[1][f]) << '\n';

    return 0;
}
