#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, groups = 0;
  long long k;

  string s;
  cin >> n >> k >> s;

  int total = count(s.begin(), s.end(), 'B');
  vector<int> gaps; // sizes of B-runs that sit between two A-runs

  for (int i = 0, j; i < n; i = j) {
    for (j = i; j < n && s[j] == s[i]; j++);
    if (s[i] == 'A') groups++;
    else if (i > 0 && j < n) gaps.push_back(j - i);
  }

  sort(gaps.begin(), gaps.end());
  for (int i = 0; i < groups - k; i++) {
    total -= gaps[i];
  }

  cout << total << '\n';
}
