#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1000000; 

int main()
{
    int n;
    cin >> n;

    ll dp[1001];

    dp[0] = 1;

    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 1;
    if (n >= 3) dp[3] = 2;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 3]) % MOD;
    }

    cout << dp[n] << '\n';
}