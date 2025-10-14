#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, vector<string>> g;
map<string, bool> vis;
vector<string> a;
bool found;

void dfs(string start, string end)
{
    vis[start] = true;

    a.emplace_back(start);

    if (start == end)
    {
        for (auto x: a)
        {
            cout << x << '\n';
        }
        found = true;
    }
    else
    {
        for (auto x: g[start])
        {
            if (!vis[x])
            {
                dfs(x, end);
            }
        }
    }

    a.pop_back(); 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        string u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
    }

    string a, b;
    cin >> a >> b;

    dfs(a, b);

    if (!found)
    {
        vis.clear();
        dfs(b, a);
    }

    if (!found)
    {
        cout << "TIDAK MUNGKIN\n";
    }
    
    return 0;
}
