#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
int parent[N];

int find(int x)
{
    cout << "di dalam find, nilai x: " << x << ", dan nilai parent[x]: " << parent[x] << endl;
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    cout << "di akhir find, nilai x: " << x << ", dan nilai parent: ";
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
    return parent[x];
}

void join(int x, int y)
{
    cout << "di dalam join, nilai x: " << x << ", dan nilai y: " << y << endl;
    x = find(x);
    y = find(y);
    cout << "di akhir join, nilai x: " << x << ", dan nilai y: " << y << endl;
    parent[x] = y;
    cout << "di akhir join, nilai parent: ";
    for (int i = 1; i <= n; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
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
        cout << "nilai x: " << x << ", nilai a: " << a << ", nilai b: " << b << endl;

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
        cout << '\n' << '\n';
    }
}