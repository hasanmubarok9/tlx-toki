#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    bool ok = false;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if (x % 2 == 0) {
            ok = true;
        }
    }
    
    cout << (ok ? "YA" : "TIDAK") << '\n';
    return 0;
}
