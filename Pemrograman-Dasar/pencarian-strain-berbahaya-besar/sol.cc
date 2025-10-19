#include <bits/stdc++.h>

using namespace std;

int n, s, p, mlg = 0; // mlg = malignant / ganas

int dfs(auto node, auto val, int x) {
    int mx = 0;
    for (int i: node[x]) {
        mx = max(mx, dfs(node, val, i));
    }
    return mx + val[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> s >> p;

    int val[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    vector<pair<string, int>> v(p);
    for (int i = 0; i < p; i++) {
        string s;
        int x;
        cin >> s >> x;
        v[i] = make_pair(s, x);
    }

    vector<int> node[n + 1];
    for (int i = p; i < n; i++) {
        int u, v;
        cin >> u >> v;

        node[u].push_back(v);
    }

    string ans;
    for (int i = 0; i < p; i++) {
        int out = dfs(node, val, v[i].second);
        if (out > mlg) {
            ans = v[i].first;
            mlg = out;
        }
    }
    cout << ans << endl << mlg << endl;
}
