#include <bits/stdc++.h>

using namespace std;

string s;
set<long long> results;

void dfs(long long total, long long last, int pos) {
  cout << "awal dfs nilai total: " << total << ", nilai last: " << last
       << ", nilai pos: " << pos << '\n';
  if (pos == s.size()) {
    cout << "masuk base case, ketika nilai pos: " << pos
         << ", dan nilai s.size(): " << s.size() << ", nilai total: " << total
         << ", dan nilai last: " << last
         << ", nilai total + last: " << total + last << endl;
    results.insert(total + last);
    cout << "return base case\n\n";
    return;
  }
  cout << "nilai pos: " << pos << ", dan nilai s[pos]: " << s[pos] << endl;
  int d = s[pos] - '0'; // digit
  cout << "nilai d: " << d << endl;

  // '+' case
  dfs(total + last, d, pos + 1);

  // '-' case
  dfs(total + last, -d, pos + 1);

  // concatenation case (extend last number)
  if (last >= 0) {
    cout << "masuk concatenation case, untuk last >= 0, nilai last: " << last
         << ", nilai last * 10 + d: " << last * 10 + d
         << ", dan nilai post + 1: " << pos + 1 << endl;
    dfs(total, last * 10 + d, pos + 1);
  } else {
    cout << "masuk concatenation case, untuk last < 0, nilai last: " << last
         << ", nilai last * 10 - d: " << last * 10 - d
         << ", dan nilai post + 1: " << pos + 1 << endl;
    dfs(total, last * 10 - d, pos + 1);
  }

  cout << "akhir dfs untuk total: " << total << ", last: " << last
       << ", dan pos: " << pos << endl;
  cout << "akhir dfs, nilai results: ";
  for (auto x : results)
    cout << x << ' ';
  cout << endl << endl;
}

int main() {
  cin >> s;
  int x = s[0] - '0'; // first digit
  cout << "nilai digit pertama: " << x << endl;
  dfs(0, x, 1);
  cout << "setelah semua, nilai results: ";
  for (auto x : results)
    cout << x << ' ';
  cout << endl;
  cout << results.size() << '\n';
}
