#include <iostream>
#include <math.h>
using namespace std;
unsigned long long a, b, c, n;

long long int power(long long int x, long long int y)
{
    if (y == 1)
    {
        return x % n;
    }

    if (y % 2 == 0)
    {
        unsigned long long temp = power(x % n, y / 2) % n;
        return (temp * temp) % n;
    }
    else
    {
        unsigned long long temp = power(x % n, y - 1) % n;
        return ((x % n) * temp) % n;
    }
}

int main()
{
    unsigned long long ans, i;
    cin >> a >> b >> c >> n;
    // ini adalah solusi yang luar biasa jenius, sangat math
    ans = a;
    for (i = 0; i < c; i++)
    {
        ans = power(ans, b);
    }
    cout << ans + 1 << endl;

    return 0;
}