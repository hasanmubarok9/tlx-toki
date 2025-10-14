#include <bits/stdc++.h>

using namespace std;

string s;
set<long long> results;

void dfs(long long total, long long last, int pos) {
  if (pos == s.size()) {
    results.insert(total + last);
    return;
  }
  int d = s[pos] - '0'; // digit

  // '+' case
  dfs(total + last, d, pos + 1);

  // '-' case
  dfs(total + last, -d, pos + 1);

  // concatenation case (extend last number)
  if (last >= 0) {
    dfs(total, last * 10 + d, pos + 1);
  } else {
    dfs(total, last * 10 - d, pos + 1);
  }
}

int main() {
  cin >> s;
  int x = s[0] - '0'; // first digit
  dfs(0, x, 1);
  cout << results.size() << '\n';
}
