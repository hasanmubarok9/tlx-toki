#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  string osn = "NOS";

  bool p = false;

  int ans = 0;

  string d = "";

  for (char ch: s) {
    cout << "nilai ch: " << ch << endl;
    if (p) {
      if (ch == 'P') {
        d += ch;
        ans += 1;
      }
    } else {
        if (ch == 'P') {
          d += ch;
          ans += 1;
          p = true;
          continue;
        }
        for (int i = 0; i < 3; i++) {
          if (ch == osn[i]) {
            d += ch;
            ans += 1;
          }
        }
      }
    cout << "nilai d: " << d << endl << endl;
  }

  cout << "nilai d: " << d << '\n';

  cout << ans << '\n';
}
