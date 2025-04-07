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
        t[i] = i + 1;
    }
    cout << "nilai a: ";
    for (int x: a) cout << x << ' ';
    cout << '\n';
    cout << "nilai t: ";
    for (int x: t) cout << x << ' ';
    cout << '\n';
    cin >> k;
    queue<pair<vector<int>, int>> q;
    set<vector<int>> vis;
    vis.insert(a);
    q.push({a, 0});
    while (!q.empty())
    {
        auto [v, d] = q.front();
        cout << "nilai v: ";
        for (int x: v) cout << x << ' ';
        cout << ", dan nilai d: " << d << '\n';
        q.pop();
        if (v == t)
        {
            cout << d << '\n';
            return 0;
        }
        for (int i = 0; i <= v.size() - k; i++)
        {
            vector<int> u = v;
            reverse(u.begin() + i, u.begin() + i + k);
            // cout << "nilai u: ";
            // for (int x: u) cout << x << ' ';
            // cout << '\n';
            if (!vis.count(u))
            {
                vis.insert(u);
                // cout << "nilai vis: ";
                // for (auto x: vis)
                // {
                //     for (int y: x) cout << y << ' ';
                //     cout << '\n';
                // }
                // cout << '\n';
                q.push({u, d + 1});
            }
            // cout << "nilai q: ";
            // queue<pair<vector<int>, int>> q2 = q;
            // while (!q2.empty())
            // {
            //     auto [v, d] = q2.front();
            //     cout << "di dalam while q2, nilai v: ";
            //     for (int x: v) cout << x << ' ';
            //     cout << "di dalam while q2, nilai d: " << d << '\n';
            //     q2.pop();
            // }
        }
    }
    cout << -1 << '\n';
    return 0;
}
