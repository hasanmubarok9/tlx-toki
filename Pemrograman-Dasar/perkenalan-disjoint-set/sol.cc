#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5; 

int n, q;
int parent[N];


int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);
    parent[x] = y;
}


int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    
    while (q--)
    {
        int x, a, b;
        cin >> x >> a >> b;

        if (x == 1)
        {
            join(a, b);
        }
        else
        {
            if (find(a) == find(b))
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "T" << endl;
            }
        }
        
    }
}
