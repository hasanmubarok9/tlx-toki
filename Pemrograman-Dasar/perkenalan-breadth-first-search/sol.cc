#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;

    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        t[i] = i + 1; // permutation identity
    }

    cin >> k;
    queue<pair<vector<int>, int>> q;
    set<vector<int>> vis;
    q.push({a, 0});
    vis.insert(a);

    while (!q.empty())
    {
        auto [v, d] = q.front();
        q.pop();

        if (v == t)
        {
            cout << d << '\n';
            return 0;
        }

        for (int i = 0; i <= n - k; i++)
        {
            vector<int> u = v;
            reverse(u.begin() + i, u.begin() + i + k);

            if (!vis.count(u)) 
            {
                vis.insert(u);
                q.push({u, d + 1});
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
