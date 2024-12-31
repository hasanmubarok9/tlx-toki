#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n;

    string s, dest;
    map<string, int> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        s += to_string(x);
        dest += to_string(i);
    }

    cout << "nilai s: " << s << ", dan nilai dest: " << dest << endl;

    cin >> k;

    if (s == dest)
    {
        cout << 0 << '\n';
        return 0;
    }

    m[s] = 1;

    queue<pair<string, int>> q;
    q.push({s, 0});

    while (!q.empty())
    {
        string str = q.front().first;
        int cnt = q.front().second;
        cout << "nilai str: " << str << ", dan nilai cnt: " << cnt << endl;
        q.pop();

        for (int i = 0; i <= n - k; i++)
        {
            string rev = str;
            reverse(rev.begin() + i, rev.begin() + i + k);

            if (m.count(rev) == 0)
            {
                if (rev == dest)
                {
                    cout << cnt + 1 << '\n';
                    return 0;
                }
                m[rev]++;
                q.push({rev, cnt + 1});
            }
        }
    }

    cout << "-1\n";
    
    return 0;
}
