#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), acc(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        acc[i] = a[i] + (i > 0 ? acc[i - 1] : 0);
    }    

    vector<int> b(k);  // Changed from n to k since there are k ducks
    for (int i = 0; i < k; i++)
    {
        cin >> b[i];
        int x = upper_bound(acc.begin(), acc.end(), b[i]) - acc.begin();
        cout << x << '\n';
    }
}