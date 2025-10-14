// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n, m, lower, upper;
long long ai[262145], cum = 0;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ai[i];
    }

    // find lower bound
    long long left = 1, right = 1e18, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        cum = 0;
        for (int i = 1; i <= n; i++)
        {
            cum += mid / ai[i];
        }
        if (cum < m)
        {
            left = mid + 1;
        }
        else if (cum > m)
        {
            right = mid - 1;
        }
        else
        {
            lower = mid;
            right = mid - 1;
        }
    }

    // find upper bound
    left = 1;
    right = 1e18;
    while (left <= right)
    {
        mid = (left + right) / 2;
        cum = 0;
        for (int i = 1; i <= n; i++)
        {
            cum += mid / ai[i];
        }
        if (cum < m)
        {
            left = mid + 1;
        }
        else if (cum > m)
        {
            right = mid - 1;
        }
        else
        {
            upper = mid;
            left = mid + 1;
        }
    }

    if (lower == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << upper - lower + 1 << endl;
    }
}
