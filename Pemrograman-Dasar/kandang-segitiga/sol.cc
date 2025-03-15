/**
 *  author: hasan.mubarok
 *  created: 02.11.2024 23:06:57
 **/

#include <iostream>

using namespace std;

const int N = 20;
int c[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
    }

    for (int i = 0; i <= n; i++)
    {
        c[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    cout << c[n][3] << '\n';

    return 0;
}
