#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;
const int dx[8] = { 2, 2, -2, -2, 1, 1, -1, -1 };
const int dy[8] = { 1, -1, 1, -1, 2, -2, 2, -2 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k, s, qi, qj;
        cin >> n >> m >> k >> s >> qi >> qj;
        cout << "nilai n: " << n << ", nilai m: " << m << ", nilai k: " << k << ", nilai s: " << s << ", nilai qi: " << qi << ", nilai qj: " << qj << endl;

        vector<vector<int>> dist(n, vector<int>(m, INF));
        queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            cout << "nilai x: " << x << ", dan nilai y: " << y << endl;
            x--; y--; // 0-based
            cout << "setelah dikurangi 1, nilai x: " << x << ", dan nilai y: " << y << endl;
            dist[x][y] = 0;
            q.emplace(x, y);
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            cout << "di dalam while, nilai x: " << x << ", dan nilai y: " << y << ", dan nilai dist[x][y]: " << dist[x][y] << endl;
            q.pop();
            if (dist[x][y] == s) continue; // cannot go further
            for (int dir = 0; dir < 8; dir++) {
                cout << "nilai dir: " << dir << endl;
                cout << "nilai dx[dir]: " << dx[dir] << endl;
                cout << "nilai dy[dir]: " << dy[dir] << endl;
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                cout << "nilai nx: " << nx << endl;
                cout << "nilai ny: " << ny << endl;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                cout << "nilai dist[nx][ny]: " << dist[nx][ny] << ", dan nilai dist[x][y]: " << dist[x][y] << ", serta nilai dist[x][y] + 1: " << dist[x][y] + 1 << endl;
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
            cout << "akhir untuk while, nilai q:\n";
            auto temp = q;
            while (!temp.empty()) {
                auto [a, b] = temp.front();
                temp.pop();
                cout << '(' << a << ',' << b << ')' << endl;
            }
            cout << endl << endl;
        }
        cout << "nilai dist[qi - 1][qj - 1]: " << dist[qi - 1][qj - 1] << endl;
        if (dist[qi - 1][qj - 1] <= s) {
            cout << "TRUE\n";
        } else {
            cout << "FALSE\n";
        }
    }
    return 0;
}
