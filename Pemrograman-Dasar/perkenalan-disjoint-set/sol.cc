#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, nn, q, Time, num[N], low[N], cmp[N]; // n = number of nodes, nn = number of SCC, Time = time of DFS, num = number of node, low = lowest node, cmp = component
vector<int> s, adj[N], nadj[N];             // adj = adjacency list, nadj = adjacency list of SCC
bitset<N> f[N];                             // f = set of nodes in SCC
bool vis[N];                                // vis = visited nodes

int tarjan(int u)
{
    num[u] = low[u] = ++Time;
    s.emplace_back(u);
    for (int v : adj[u])
    {
        if (!cmp[v])
        {
            low[u] = min(low[u], num[v] ? num[v] : tarjan(v));
        }
    }

    if (low[u] == num[u])
    {
        int v;
        nn++;
        do
        {
            v = s.back();
            s.pop_back();
            cmp[v] = nn;
        } while (v != u);
    }
    return low[u];
}

void dfs(int u)
{
    vis[u] = true;
    f[u].set(u);
    for (int v : nadj[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
        f[u] |= f[v];
    }    
}

int main()
{
    cin >> n >> q;

    while (q--)
    {
        int x, a, b;
        cin >> x >> a >> b;

        if (x == 1)
        {
            // join a and b
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);

            // TODO: join a and b
            tarjan(a);
        }
        else
        {
            // find if a and b are in the same SCC
            if (cmp[a] == cmp[b])
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "T" << endl;
            }
        }
    }
}