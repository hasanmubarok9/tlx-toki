#include <bits/stdc++.h>

using namespace std;

vector<int> permutation;
int n = 3;
bool chosen[4];

void search()
{
    cout << "vector di awal fungsi " << '\n';
    for (int i = 0; i < permutation.size(); i++)
    {
        cout << permutation[i];
    }
    cout << '\n';
    cout << '\n';
    cout << "nilai chosen " << '\n';
    for (int i = 0; i < sizeof(chosen) / sizeof(chosen[0]); i++)
    {
        cout << chosen[i];
    }
    cout << '\n';
    cout << '\n';
    if (permutation.size() == n)
    {
        cout << "nilai akhir " << '\n';
        for (int i = 0; i < permutation.size(); i++)
        {
            cout << permutation[i];
        }
        cout << '\n';
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main()
{
    search();
    return 0;
}