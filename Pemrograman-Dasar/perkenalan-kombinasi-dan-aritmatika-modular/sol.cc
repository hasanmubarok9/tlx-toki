#include <iostream>

using namespace std;

const int N = 1005, MOD = 1e9 + 7;

int c[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i <= n; i++)
    {
        c[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }

    int res = 0;
    for (int i = a; i <= b; i++)
    {
        res += c[n][i];
        res %= MOD;
    }

    cout << res << '\n';

    return 0;
}
