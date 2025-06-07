#include <bits/stdc++.h>

using namespace std;

int n, par[107];
vector<tuple<int, int, int>> g; // weight, node1, node2

int root(int x)
{
    if (par[x] == x)
    {
        return x;
    }
    return par[x] = root(par[x]);
}

void join(int x, int y)
{
    x = root(x);
    y = root(y);

    if (x != y)
    {
        par[x] = y;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;

            if (i != j)
            {
                g.emplace_back(w, i, j);
            }
        }
    }

    sort(g.begin(), g.end());

    int ans = 0;
    for (auto [w, u, v] : g)
    {
        if (root(u) != root(v))
        {
            join(u, v);
            ans += w;
        }
    }

    cout << ans << '\n';
    
    return 0;
}