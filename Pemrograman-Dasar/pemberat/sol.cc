/**
 *  author: hasan.mubarok
 *  created: 02.11.2024 23:06:57
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k, b;
    cin >> k >> b;

    long long x = abs(k - b);
    int i = 0;

    vector<int> res;
    while (x > 0)
    {
        if (x & 1)
        {
            res.push_back(1LL << i);
        }
        x >>= 1;
        i++;
    }

    reverse(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << '\n';
    }
    
    return 0;
}

