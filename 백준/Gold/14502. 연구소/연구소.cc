#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int minArea = 0;

void bfs(vector<vector<int>>& grid, deque<pair<int, int>>& queue) {
    vector<vector<int>> gridCopy = grid;
    deque<pair<int, int>> queueCopy = queue;

    int w = static_cast<int>(grid[0].size());
    int h = static_cast<int>(grid.size());

    vector<vector<bool>> visited(h, vector<bool>(w));

    while (!queueCopy.empty()) {
        pair<int, int> current = queueCopy.front();
        queueCopy.pop_front();

        for (int i = 0; i < 4; i++) {
            int ny = current.first + dy[i];
            int nx = current.second + dx[i];

            if (0 <= ny && ny < h && 0 <= nx && nx < w) {
                if (!visited[ny][nx] && gridCopy[ny][nx] == 0) {
                    gridCopy[ny][nx] = 2;
                    visited[ny][nx] = true;
                    queueCopy.emplace_back(make_pair(ny, nx));
                }
            }
        }
    }

    int safeArea = 0;

    for (int i = 0; i < h; i++) {
        safeArea += static_cast<int>(count(gridCopy[i].begin(), gridCopy[i].end(), 0));
    }

    minArea = max(safeArea, minArea);
}

void buildWalls(vector<vector<int>>& grid, vector<vector<bool>>& visited, deque<pair<int, int>>& queue, int count) {
    if (count == 3) {
        bfs(grid, queue);
        return;
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 0 && !visited[i][j]) {
                grid[i][j] = 1;
                visited[i][j] = true;
                buildWalls(grid, visited, queue, count + 1);
                grid[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    deque<pair<int, int>> queue;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;

            grid[i][j] = num;

            if (num == 2) {
                queue.emplace_back(make_pair(i, j));
            }
        }
    }

    buildWalls(grid, visited, queue, 0);
    cout << minArea << "\n";

    return 0;
}
