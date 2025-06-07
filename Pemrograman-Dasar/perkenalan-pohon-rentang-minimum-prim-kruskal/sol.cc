#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, par[107];
vector<pair<ll, pair<ll, ll>>> v;

ll root(ll x)
{
    cout << "masuk root, nilai x: " << x << endl;
    if (par[x] == x)
    {
        cout << "masuk par[x] == x, nilai x: " << x << endl;
        return x;
    }
    cout << "masuk par[x] != x, nilai x: " << x << endl;
    par[x] = root(par[x]);
    cout << "di akhir root, nilai par[x]: " << par[x] << endl;
    return par[x];
}

void join(ll x, ll y)
{
    cout << "masuk join, nilai x: " << x << ", nilai y: " << y << endl;
    x = root(x);
    y = root(y);
    cout << "setelah root, nilai x: " << x << ", nilai y: " << y << endl;
    if (x != y)
    {
        cout << "masuk x != y, nilai x: " << x << ", nilai y: " << y << endl;
        par[x] = y;
    }
    cout << "di akhir join, nilai par: ";
    for (ll i = 0; i <= n; i++)
    {
        cout << par[i] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n;

    for (ll i = 1; i <=n; i++)
    {
        par[i] = i;
    }

    cout << "nilai par: ";
    for (ll i = 0; i < n; i++)
    {
        cout << par[i] << " ";
    }
    cout << endl;

    ll sz = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll x;
            cin >> x;
            cout << "nilai x: " << x << endl;
            if (i != j)
            {
                cout << "masuk i != j, nilai i: " << i << ", nilai j: " << j << endl;
                v.emplace_back(x, make_pair(i, j));
            }
        }
        cout << '\n';
    }

    cout << "nilai v:\n";
    for (pair<ll, pair<ll, ll>> i : v)
    {
        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }

    ll ans = 0;
    sort(v.begin(), v.end());
    cout << "nilai v setelah sort:\n";
    for (pair<ll, pair<ll, ll>> i : v)
    {
        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }
    cout << '\n';
    for (pair<ll, pair<ll, ll>> i : v)
    {
        cout << "nilai i: " << i.first << ", " << i.second.first << ", " << i.second.second << endl;
        if (root(i.second.first) != root(i.second.second))
        {
            cout << "masuk if, nilai i: " << i.first << ", " << i.second.first << ", " << i.second.second << endl;
            ans += i.first;
            cout << "nilai ans: " << ans << endl;
            join(i.second.first, i.second.second);
        }
        cout << "akhir loop untuk i: " << i.first << ", " << i.second.first << ", " << i.second.second << endl << endl;
    }

    cout << ans << endl;
    return 0;
}