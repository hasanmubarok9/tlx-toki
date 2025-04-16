#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    map<int, vector<pair<int, int>>, greater<int>> cellsByHeight;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int h = grid[i][j];
            cellsByHeight[h].emplace_back(i, j);
        }
    }

    vector<int> sorted_heights;
    for (auto& entry : cellsByHeight) {
        sorted_heights.push_back(entry.first);
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> parent(n * m, -1);
    vector<int> size(n * m, 0);
    int max_islands = 0;
    int current_count = 0;

    for (int s : sorted_heights) {
        auto& cells = cellsByHeight[s];
        for (auto& cell : cells) {
            int i = cell.first;
            int j = cell.second;
            if (!visited[i][j]) {
                int idx = i * m + j;
                parent[idx] = idx;
                size[idx] = 1;
                current_count++;
                visited[i][j] = true;

                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto& dir : directions) {
                    int ni = i + dir.first;
                    int nj = j + dir.second;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (visited[ni][nj]) {
                            int neighbor_idx = ni * m + nj;
                            int root1 = find(idx, parent);
                            int root2 = find(neighbor_idx, parent);
                            if (root1 != root2) {
                                if (size[root1] < size[root2]) {
                                    swap(root1, root2);
                                }
                                parent[root2] = root1;
                                size[root1] += size[root2];
                                current_count--;
                            }
                        }
                    }
                }
            }
        }
        if (current_count > max_islands) {
            max_islands = current_count;
        }
    }

    cout << max_islands << endl;

    return 0;
}