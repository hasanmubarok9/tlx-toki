#include <iostream>
using namespace std;
unsigned long a, b;
unsigned long long res;
int mod = 1000000;

unsigned long long findPower(long a, long b)
{
    if (b == 1)
    {
        return a % mod;
    }

    if (b % 2 == 0)
    {
        unsigned long long temp = findPower(a % mod, b / 2) % mod;
        return (temp * temp) % mod;
    }
    else
    {
        unsigned long long temp = findPower(a % mod, b - 1) % mod;
        return ((a % mod) * temp) % mod;
    }
}
int main()
{
    cin >> a >> b;
    res = findPower(a, b);
    cout << res << endl;
}