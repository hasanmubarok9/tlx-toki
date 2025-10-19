#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, p;
    cin >> n >> s >> p;

    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) cin >> val[i];

    vector<string> virusName(p);
    vector<int> root(p);

    for (int i = 0; i < p; i++) {
        cin >> virusName[i] >> root[i];
    }

    vector<vector<int>> child(n + 1);
    for (int i = 0; i + p < n; i++) {
        int u, v; // u infected v
        cin >> u >> v;
        child[u].push_back(v);
    }

    /* Iterative post-order dfs
     * dp[x] = maximum total stay-time starting from x
     */
    vector<int> dp(n + 1, 0);
    vector<char> seen(n + 1, 0); // 0 = not visited, 1 = in stack, 2 = finished

    for (int r: root) {
        if (seen[r]) continue; // already processed in a previous dfs

        // stack of pairs (node, next_child_index)
        vector<pair<int, int>> st;
        st.emplace_back(r, 0);
        seen[r] = 1;

        while (!st.empty()) {
            int node = st.back().first;
            int &idx = st.back().second;

            if (idx < (int)child[node].size()) {
                int nxt = child[node][idx++];
                if (!seen[nxt]) {
                    st.emplace_back(nxt, 0);
                    seen[nxt] = 1;
                } else {
                    int best = 0;
                    for (int c: child[node]) {
                        best = max(best, dp[c]);
                    }
                    dp[node] = val[node] + best;
                    seen[node] = 2;
                    st.pop_back();
                }
            }
        }
    }

    /*
     * Pick the most severe virus, guaranteed to be unique
     */
    int best = -1;
    string ans;
    for (int i = 0; i < p; i++) {
        if (dp[root[i]] > best) {
            best = dp[root[i]];
            ans = virusName[i];
        }
    }

    cout << ans << endl << best << endl;
    return 0;
}
