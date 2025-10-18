#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int k = s.size();
    vector<int> digits(k);
    for (int i = 0; i < k; i++) {
        digits[i] = s[i] - '0';
    }

    // number of operator operations
    int pos = k - 1;
    long long totalComb = 1;
    for (int i = 0; i < pos; i++) {
        totalComb *= 3LL;
    } // 3 ^ (k - 1)

    unordered_set<long long> results;
    results.reserve(totalComb * 2);

    for (long long mask = 0; mask < totalComb; mask++) {
      cout << "nilai mask: " << mask << endl;
      long long tmp = mask;
      long long total = 0;
      long long num = digits[0];
      long long sign = 1; // current number sign

      for (int i = 0; i < pos; i++) {
          cout << "nilai i: " << i << ", dan nilai tmp: " << tmp << endl;
          int op = tmp % 3; // 0: concat, 1: '+', 2: '-'
          cout << "nilai op: " << op << endl;
          tmp /= 3;
          cout << "nilai tmp setelah dibagi 3: " << tmp << endl;
          int d = digits[i + 1];
          cout << "nilai d: " << d << endl;

          if (op == 0) { // concat
              cout << "masuk concat, nilai num: " << num << ", dan nilai d: " << d << endl;
              num = num * 10 + d;
              cout << "nilai num yang baru: " << num << endl;
          } else { // finish current number
              cout << "masuk finish current number, nilai sign: " << sign << ", dan nilai num: " << num << endl;
              total += sign * num;
              cout << "nilai total: " << total << endl;
              sign = (op == 1) ? 1 : -1;
              cout << "nilai sign yang baru: " << sign << endl;
              num = d;
              cout << "nilai num yang baru: " << num << endl;
          }
      }
      cout << "nilai sign: " << sign << ", dan nilai num: " << num << ", nilai sign * num: " << sign * num << endl;
      total += sign * num; // add last number
      cout << "nilai total: " << total << endl;
      results.insert(total);
      cout << "akhir for untuk mask: " << mask << endl << endl;
    }
    cout << "nilai results: ";
    for (auto x: results) cout << x << ' ';
    cout << endl;

    cout << results.size() << '\n';
    return 0;
}
