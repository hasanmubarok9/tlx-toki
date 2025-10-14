#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> h(n, 0), v;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cin >> m;

    sort(h.begin(), h.end());

    // for (int i = 0; i < n; i++)
    // {
    //     cout << h[i] << " ";
    // }

    // cout << "\n";

    v.assign(m, n /m);

    for (int i = 0; i < n % m; i++)
    {
        v[i]++;
    }
    
    do
    {
        /* code */
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " ";
        // }
        // cout << "\n";

        int idx = 0;
        bool valid = true;

        for (int i = 0; i < m - 1; i++)
        {
            idx += v[i];

            if (h[idx] == h[idx - 1]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            idx = 0;

            for (int i = 0; i < m - 1; i++) {
                idx += v[i];
                cout << h[idx] << " ";
            }

            break;
        }
        
    } while (prev_permutation(v.begin(), v.end()));
    

    return 0;
}
