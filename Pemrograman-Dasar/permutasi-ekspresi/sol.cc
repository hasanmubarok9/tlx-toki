#include <bits/stdc++.h>

using namespace std;

string s;
unordered_set<int> results;

void dfs(int total, int last, int pos) {

  if (pos == s.size()) {
    results.insert(total + last);
    return;
  }

  int d = s[pos] - '0';

  // '+' case
  dfs(total + last, d, pos + 1);

  // '-' case
  dfs(total + last, -d, pos + 1);

  // concatenation case
  if (last >= 0) {
    dfs(total, last * 10 + d, pos + 1);
  } else {
    dfs(total, last * 10 - d, pos + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;

  int x = s[0] - '0'; // the first digit
  dfs(0, x, 1);

  cout << results.size() << '\n';
}
