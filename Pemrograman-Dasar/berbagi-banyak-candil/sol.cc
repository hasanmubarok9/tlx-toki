#include <iostream>

using namespace std;

int main()
{
    long long b, c, d;

    cin >> b >> c >> d;

    long long x = c - d;

    long long res = 0;
    if (x == 0)
    {
        res = max(0ll, b - c);
    }
    else
    {
        for (long long i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (i <= b && c % i == d)
                {
                    res++;
                }
                long long y = x / i;
                if (i != y && y <= b && c % y == d)
                {
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}