#include <bits/stdc++.h>

using namespace std;

using ll = long double;

int n, m, x; // n = rows, m = columns, x = the number of operations

// transpose matrix
vector<vector<ll>> transpose(vector<vector<ll>> matrix)
{
    vector<vector<ll>> result(matrix[0].size(), vector<ll>(matrix.size()));

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << "nilai i: " << i << " nilai j: " << j << ", dan nilai matrix[i][j]: " << matrix[i][j] << endl;
            cout << "nilai j: " << j << " nilai i: " << i << endl;
            result[j][i] = matrix[i][j];
        }

    return result;
}

// reflect matrix horizontally
vector<vector<ll>> reflect_horizontal(vector<vector<ll>> matrix)
{
    vector<vector<ll>> result(matrix.size(), vector<ll>(matrix[0].size()));

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            result[i][j] = matrix[i][matrix[0].size() - j - 1];

    return result;
}

// reflect matrix vertically
vector<vector<ll>> reflect_vertical(vector<vector<ll>> matrix)
{
    vector<vector<ll>> result(matrix.size(), vector<ll>(matrix[0].size()));

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++)
            result[i][j] = matrix[matrix.size() - i - 1][j];

    return result;
}

int main()
{
    cin >> n >> m >> x;

    vector<vector<ll>> matrix(n, vector<ll>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < x; i++)
    {
        string operation;
        cin >> operation;

        if (operation == "_") {
            matrix = reflect_horizontal(matrix);
        } else if (operation == "|") {
            matrix = reflect_vertical(matrix);
        } else if (operation == "90") {
            matrix = transpose(matrix);
            // matrix = reflect_vertical(matrix);
        } else if (operation == "180") {
            matrix = reflect_horizontal(matrix);
            matrix = reflect_vertical(matrix);            
        } else if (operation == "270") {
            matrix = transpose(matrix);
            matrix = reflect_horizontal(matrix);        
        }
    }

    // output matrix
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << fixed << setprecision(0) << matrix[i][j] << (j == matrix[0].size() - 1 ? '\n' : ' ');
    }

    return 0;
}