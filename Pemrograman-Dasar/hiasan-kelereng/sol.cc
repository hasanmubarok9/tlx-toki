#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(26, 0);
    for (int i = 0; i < n; i++) {
        a[s[i] - 'A']++;
    }

    vector<int> x;

    for (int i = 0; i < 26; i++) {
        if (a[i] > 0) {
            x.push_back(a[i]);
        }
    }

    if (x.size() < 3) {
        cout << -1 << '\n';
        return 0;
    }

    // sort(x.begin(), x.end(), [](int a, int b) {
    //     return a > b;
    // });

    sort(x.rbegin(), x.rend());
    
    int ans = x[2] * 3 + (x[0] > x[2]) + (x[1] > x[2]);

    cout << ans << '\n';
}
