#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int maxArea = 0;

int getSafeArea(const vector<vector<int>>& grid) {
    int size = 0;

    vector<vector<int>> gridCopy(grid.begin(), grid.end());

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(gridCopy[i][j] == 0) {
                size++;
            }
        }
    }

    return size;
}

void spreadFire(vector<vector<int>>& grid) {
    deque<pair<int, int>> queue;

    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid[0].size(); j++) {
            if(grid[i][j] == 2) {
                queue.emplace_back(j, i);
            }
        }
    }

    while(!queue.empty()) {
        pair<int, int> current = queue.front();
        queue.pop_front();

        int x = current.first, y = current.second;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if(0 <= nx && nx < grid[0].size() && 0 <= ny && ny < grid.size()) {
                if(grid[ny][nx] == 0) {
                    grid[ny][nx] = 2;
                    queue.emplace_back(nx, ny);
                }
            } 
        }
    }
}

void createWall(vector<vector<int>>& grid, int idx, int count) {
    if(count == 3) {
        vector<vector<int>> gridCopy(grid.begin(), grid.end());

        spreadFire(gridCopy);
        maxArea = max(maxArea, getSafeArea(gridCopy));
        return;
    }

    for(int i = idx; i < grid.size() * grid[0].size(); i++) {
        int y = i / grid[0].size();
        int x = i % grid[0].size();

        if(grid[y][x] == 0) {
            grid[y][x] = 1;
            createWall(grid, i, count + 1);
            grid[y][x] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 0: 빈 칸, 1: 벽, 2: 불
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    createWall(grid, 0, 0);

    cout << maxArea << "\n";

    return 0;
}