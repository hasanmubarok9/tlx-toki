#include <bits/stdc++.h>

using namespace std;
int n, c;
int coins[500], memo[50000];
bool computed[50000];

int solve(int x)
{
    if (x == 0)
        return 0;
    if (computed[x])
        return memo[x];

    int best = 5000;

    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= x)
        {
            best = min(best, solve(x - coins[i]) + 1);
        }
    }

    computed[x] = true;
    memo[x] = best;

    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    // get input of coins
    cin >> c;
    cout << solve(c) << endl;
    return 0;
}