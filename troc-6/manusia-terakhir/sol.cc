#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x, y;
    cin >> n >> x >> y;

    if (n < (abs(x) + abs(y)) || (n - (x + y)) % 2)
    {
        cout << -1 << '\n';
        return 0;
    }

    int r = (n - (x + y)) / 2;

    int a, b, c, d;

    if (x >= 0)
    {
        b = x;
        d = 0;
    }
    else
    {
        b = 0;
        d = -x;
    }

    c = r - d;
    a = n - (b + c + d);

    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    
    return 0;
}
