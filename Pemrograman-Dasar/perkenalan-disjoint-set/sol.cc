#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
int parent[N];

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
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
            // adj[a].emplace_back(b);
            // adj[b].emplace_back(a);

            // // TODO: join a and b
            // tarjan(a);
        }
        else
        {
            // find if a and b are in the same SCC
            // if (cmp[a] == cmp[b])
            // {
            //     cout << "Y" << endl;
            // }
            // else
            // {
            //     cout << "T" << endl;
            // }
        }
    }
}