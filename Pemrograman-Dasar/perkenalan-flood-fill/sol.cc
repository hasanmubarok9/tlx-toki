#include <bits/stdc++.h>

using namespace std;

int xc, yc, xb, yb;
int c, r;

int dfs(int x, int y, vector<string> &yard, vector<vector<bool>> &visited)
{
    if (x < 0 || x >= r || y < 0 || y >= c || visited[x][y] || yard[x][y] == '#')
    {
        return 0;
    }

    visited[x][y] = true;
    int area = 1;

    area += dfs(x - 1, y, yard, visited);
    area += dfs(x + 1, y, yard, visited);
    area += dfs(x, y - 1, yard, visited);
    area += dfs(x, y + 1, yard, visited);

    return area;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> r;

    vector<string> yard(r);

     // Read the grid row-by-row
    for (int i = 0; i < r; i++)
    {
        cin >> yard[i]; // Read the entire row as a string
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (yard[i][j] == 'K')
            {
                xc = i, yc = j;
            }
            if (yard[i][j] == 'B')
            {
                xb = i, yb = j;
            }
        }
    }

    vector<vector<bool>> visited(r, vector<bool>(c, false));

    int a = dfs(xc, yc, yard, visited);

    fill(visited.begin(), visited.end(), vector<bool>(c, false));

    int b = dfs(xb, yb, yard, visited);

    if (a == b)
    {
        cout << "SERI\n";
    }
    else
    {
        cout << (a > b ? "K" : "B") << ' ' << abs(a - b) << '\n';
    }
    return 0;
}
