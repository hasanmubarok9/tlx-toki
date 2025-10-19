#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    int k = s.size();
    vector<int> digits(k);

    for (int i = 0; i < k; i++) {
       digits[i] = s[i] - '0';
    }

    int pos = k - 1;
    int totalComb = 1;
    for (int i = 0; i < pos; i++) {
        totalComb *= 3LL;
    } // 3 ^ (k - 1)

    unordered_set<int> results;

    for (int mask = 0; mask < totalComb; mask++) {
        int tmp = mask;
        int total = 0;
        int sign = 1;
        int num = digits[0];
        for (int i = 0; i < pos; i++) {
           int d = digits[i + 1];
           int op = tmp % 3;
           tmp /= 3;
           if (op == 0) {
               num = num * 10 + d;
           } else {
               total += sign * num;
               sign = (op == 1 ? 1 : -1);
               num = d;
           }
        }
        total += sign * num;
        results.insert(total);
    }
    cout << results.size() <<  '\n';
}
