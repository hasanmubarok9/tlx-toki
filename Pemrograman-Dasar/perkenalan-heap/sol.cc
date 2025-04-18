#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int> pq;

    while (n--)
    {
        int x;
        cin >> x;

        if (x == 1)
        {
            int y;
            cin >> y;
            pq.push(y);
        }
        else if (x == 2)
        {
            cout << pq.top() << endl;
        }
        else
        {
            pq.pop();
        }
    }
}
