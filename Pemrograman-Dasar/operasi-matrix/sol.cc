#include <bits/stdc++.h>
using namespace std;
using ll = long double;

int n, m, x; // n = rows, m = columns, x = number of operations

// Rotate matrix 90° clockwise.
vector<vector<ll>> rotate90(const vector<vector<ll>> &matrix) {
    int R = matrix.size(), C = matrix[0].size();
    // After a 90° clockwise rotation, new dimensions become C x R.
    vector<vector<ll>> result(C, vector<ll>(R));
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            result[i][j] = matrix[R - 1 - j][i];
        }
    }
    return result;
}

// Reflect matrix horizontally (reverse each row).
vector<vector<ll>> reflect_horizontal(const vector<vector<ll>> &matrix) {
    int R = matrix.size(), C = matrix[0].size();
    vector<vector<ll>> result = matrix;
    for (int i = 0; i < R; i++)
        reverse(result[i].begin(), result[i].end());
    return result;
}

// Reflect matrix vertically (reverse the order of rows).
vector<vector<ll>> reflect_vertical(const vector<vector<ll>> &matrix) {
    vector<vector<ll>> result = matrix;
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cin >> n >> m >> x;
    vector<vector<ll>> matrix(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    for (int op = 0; op < x; op++) {
        string operation;
        cin >> operation;
        if (operation == "_") {
            matrix = reflect_horizontal(matrix);
        } else if (operation == "|") {
            matrix = reflect_vertical(matrix);
        } else if (operation == "90") {
            // "90" means 90° counterclockwise,
            // which is equivalent to 270° clockwise (apply rotate90 three times).
            for (int i = 0; i < 3; i++) {
                matrix = rotate90(matrix);
            }
        } else if (operation == "180") {
            // 180° rotation: apply rotate90 twice.
            for (int i = 0; i < 2; i++) {
                matrix = rotate90(matrix);
            }
        } else if (operation == "270") {
            // "270" means 270° counterclockwise,
            // which is equivalent to 90° clockwise (apply rotate90 once).
            matrix = rotate90(matrix);
        }
    }

    // Output the resulting matrix.
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << fixed << setprecision(0) << matrix[i][j] 
                 << (j == matrix[0].size() - 1 ? "\n" : " ");
    }
    return 0;
}
