#include <bits/stdc++.h>
using namespace std;

int n, s, p, gns = 0;

int dfs(auto node[], int val[], int x)
{
    // cout << "di dalam dfs, nilai node:\n";
    // for (int i = 0; i < n + 1; i++) {
    //     cout << i << ": ";
    //     for (auto x: node[i]) {
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << "di dalam dfs, nilai val: ";
    // for (int i = 1; i < n + 1; i++) {
    //     cout  << val[i] << ' ';
    // }
    // cout << endl;
    cout << "di dalam dfs, nilai x: " << x << endl;
    int mx = 0;
    for (auto i : node[x])
    {
        cout << "nilai i: " << i << endl;
        mx = max(mx, dfs(node, val, i));
    }
    cout << "akhir dfs, nilai x: " << x << ",  nilai val[x]: " << val[x] << ", nilai mx: " << mx << ", dan nilai mx + val[x]: " << mx + val[x] << endl << endl;
    return mx + val[x];
}

int main()
{
    cin >> n >> s >> p;
    cout << "nilai n: " << n << " nilai s: " << s << " nilai p: " << p << '\n';
    int val[n + 1];
    vector<int> node[n + 1];
    pair<string, int> v[p]; // virus
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        cout << "nilai val[" << i << "]: " << val[i] << '\n';
    }
    for (int i = 0; i < p; i++)
    {
        string s;
        int x;
        cin >> s >> x;
        cout << "nilai s: " << s << " nilai x: " << x << '\n';
        v[i] = {s, x};
        cout << "nilai v[" << i << "]: " << v[i].first << " " << v[i].second << '\n';
    }
    for (int i = p; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << "nilai u: " << u << " nilai v: " << v << '\n';
        node[u].push_back(v);
    }
    string ans;
    for (int i = 0; i < p; i++)
    {
        cout << "nilai i: " << i << ", nilai v[i].first: " << v[i].first << ", nilai v[i].second: " << v[i].second << ", dan nilai s: " << s << '\n';
        int out = dfs(node, val, v[i].second);
        if (out > gns)
        {
            gns = out;
            ans = v[i].first;
        }
    }

    cout << ans << '\n'
         << gns << '\n';
}
