/**
 *  author: tourist
 *  created: 02.11.2024 23:06:57
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y, p;
    cin >> n >> x >> y >> p;
    if (x > y)
    {
        swap(x, y);
    }
    x = max(x - n, 0);
    y += n;
    cout << (x == p || y == p ? "YA" : "TIDAK") << '\n';
    return 0;
}
