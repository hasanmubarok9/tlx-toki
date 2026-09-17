#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string original, msg1, msg2;
  cin >> original >> msg1 >> msg2;

  int arr[100], inv_arr[100];

  for (int i = 'A'; i <= 'Z'; i++) {
    arr[i] = -1;
    inv_arr[i] = -1;
  }

  bool flag = false;
  for (int i = 0; i < n; i++) {
    int c = msg1[i], c_org = original[i];
    if (arr[c] == -1 && inv_arr[c_org] == -1) {
      arr[c] = c_org;
      inv_arr[c_org] = c;
    } else {
      if (arr[c] == c_org && inv_arr[c_org] == c) continue;
      else {
        flag = true;
        break;
      }
    }

  }

  if (flag) {
    cout << "Pak Dengklek bingung\n";
    return 0;
  } 
  for (int i = 0; i < n; i++) {
    if (arr[i] == -1) {
      cout << '?';
    } else {
      cout << char('A' + arr[i]);
    }
  }
  cout << '\n';

  return 0;
}
