#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, m, a[100005], mx = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    sort(a + 1, a + n + 1);

    ll l = 0, r = mx, note = -1;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        ll cut = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > mid)
            {
                cut += a[i] - mid;
            }
        }
        if (cut >= m)
        {
            note = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << note << '\n';
    return 0;
}