#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(vector<vector<int>>& grid) {
    deque<pair<int, int>> queue;
    queue.emplace_back(make_pair(0, 0));

    while (!queue.empty()) {
        pair<int, int> current = queue.front();
        queue.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (0 <= nx && nx < grid[0].size() && 0 <= ny && ny < grid.size()) {
                if (grid[ny][nx] == 1) {
                    grid[ny][nx] += grid[current.second][current.first];
                    queue.emplace_back(make_pair(nx, ny));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++) {
        string r;
        cin >> r;

        vector<int> row;

        for (char c: r) {
            row.emplace_back(c - '0');
        }

        grid[i] = row;
    }

    bfs(grid);

    cout << grid[n - 1][m - 1] << "\n";

    return 0;
}
