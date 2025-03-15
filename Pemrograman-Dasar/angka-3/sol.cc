#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    
    vector<long long> res;

    while (n > 0)
    {
        res.push_back(n % x);
        n /= x;
    }

    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}