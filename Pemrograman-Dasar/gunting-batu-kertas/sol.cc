#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;

    int g = 0, b = 0, k = 0;
    for (int i = 0; i < n; i++) {
        if (s2[i] == 'G') g++;
        else if (s2[i] == 'B') b++;
        else k++;
    }

    for (int i = 0; i < n; i++) {
        if (s1[i] == 'G' && k > 0) {
            ans++;
            k--;
        }
        else if (s1[i] == 'B' && b > 0) {
            ans++;
            b--;
        } else if (g > 0) {
            ans++;
            g--;
        }
    }

    cout << ans << '\n';
}
