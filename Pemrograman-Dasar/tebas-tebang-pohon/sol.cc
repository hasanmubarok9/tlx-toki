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

    cout << "nilai a: ";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << '\n';

    sort(a + 1, a + n + 1);

    cout << "nilai a setelah di sort: ";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << '\n';

    ll l = 0, r = mx, note = -1;
    while (l <= r)
    {
        cout << "nilai l: " << l << " nilai r: " << r << '\n';
        ll mid = (l + r) >> 1;
        cout << "nilai mid: " << mid << '\n';
        ll cut = 0;
        for (int i = 1; i <= n; i++)
        {
            cout << "nilai a[i]: " << a[i] << " nilai mid: " << mid << ", nilai a[i] - mid: " << a[i] - mid << '\n';
            if (a[i] > mid) cut += a[i] - mid;
            cout << "nilai cut: " << cut << '\n';
        }
        cout << "nilai cut: " << cut << " nilai m: " << m << '\n';
        if (cut >= m)
        {
            cout << "masuk kanan\n";
            note = mid;
            l = mid + 1;
        }
        else
        {
            cout << "masuk kiri\n";
            r = mid - 1;
        }

        cout << "akhir while, nilai l: " << l << " nilai r: " << r << " nilai note: " << note << '\n' << '\n';
    }
    cout << note << '\n';
    return 0;
}