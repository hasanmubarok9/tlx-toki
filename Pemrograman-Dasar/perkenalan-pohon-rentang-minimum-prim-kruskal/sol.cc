#include <bits/stdc++.h>

using namespace std;

int n, par[107];
vector<tuple<int, int, int>> g; // weight, node1, node2

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

    for (auto [w, u, v] : g)
    {
        cout << w << " " << u << " " << v << endl;
    }
    
    return 0;
}