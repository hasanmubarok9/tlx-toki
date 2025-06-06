#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, par[107];
vector<pair<ll, pair<ll, ll>>> v;

ll root(ll x) {
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
}

void join(ll x, ll y) {
    x = root(x);
    y = root(y);
    if (x != y) par[x] = y;
}

int main() {
    cin >> n;

    for (ll i = 0; i < n; i++) {
        par[i] = i;
    }

    ll sz = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll x;
            cin >> x;
            if (i != j) v.emplace_back(x, make_pair(i, j));
        }
    }
    
    ll ans = 0;
    sort(v.begin(), v.end());
    for (pair<ll, pair<ll, ll>> i : v) {
        if (root(i.second.first) != root(i.second.second)) {
            ans += i.first;
            join(i.second.first, i.second.second);
        }
    }

    cout << ans << endl;
    return 0;
}