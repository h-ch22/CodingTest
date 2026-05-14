#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Group {
    int originalNumber, cellCount;

    Group(): originalNumber(-1), cellCount(0) {}
};

void bfs(const vector<vector<int>>& grid, vector<vector<int>>& groupGrid, const int originalX, const int originalY, const int groupId) {
    const int n = grid.size();
    deque<pair<int, int>> queue;

    queue.emplace_back(originalX, originalY);
    groupGrid[originalY][originalX] = groupId;

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        int x = current.first, y = current.second;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n && groupGrid[ny][nx] == -1 && grid[ny][nx] == grid[y][x]) {
                groupGrid[ny][nx] = groupId;
                queue.emplace_back(nx, ny);
            }
        }
    }
}

int getScore(const vector<Group>& groups, const vector<vector<int>>& borders, const int maxGroups) {
    int score = 0;

    for(int i = 0; i < maxGroups; i++) {
        for(int j = i + 1; j < maxGroups; j++) {
            score += (groups[i].cellCount + groups[j].cellCount) * groups[i].originalNumber * groups[j].originalNumber * borders[i][j];
        }
    }

    return score;
}

vector<vector<int>> rotate(const vector<vector<int>>& grid) {
    const int n = grid.size();
    const int center = n / 2;

    vector<vector<int>> nextGrid(n, vector<int>(n));

    nextGrid[center][center] = grid[center][center];

    // Top
    // 2,0 -> 0,2
    // 2,1 -> 1,2

    // Right
    // 3,2 -> 2,1
    // 4,2 -> 2,0

    // Left
    // 0,2 -> 2,4
    // 1,2 -> 2,3

    // Bottom
    // 2,4 -> 4,2
    // 2,3 -> 3,2

    // y -> x, x -> n - 1 - x
    for(int x = 0; x < n; x++) {
        if(x == center) {
            continue;
        }

        nextGrid[n - 1 - x][center] = grid[center][x];
    }

    for(int y = 0; y < n; y++) {
        if(y == center) {
            continue;
        }

        nextGrid[center][y] = grid[y][center];
    }

    const vector<pair<int, int>> offsets = {
        { 0, 0 },
        { center + 1, 0 },
        { 0, center + 1 },
        { center + 1, center + 1 }
    };

    for(const pair<int, int>& offset: offsets) {
        int sx = offset.first, sy = offset.second;

        for(int y = 0; y < center; y++) {
            for(int x = 0; x < center; x++) {
                nextGrid[sy + x][sx + center - 1 - y] = grid[sy + y][sx + x];
            }
        }
    }

    // for(int y = 0; y < n; y++) {
    //     for(int x = 0; x < n; x++) {
    //         cout << nextGrid[y][x] << " ";
    //     }

    //     cout << "\n";
    // }

    // cout << "\n";

    return nextGrid;
}

vector<vector<int>> getGroupGrid(const vector<vector<int>>& grid, const int n, int& currentGroupId) {
    vector<vector<int>> groupGrid(n, vector<int>(n, -1));
    
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < n; x++) {
            if(groupGrid[y][x] == -1) {
                bfs(grid, groupGrid, x, y, currentGroupId);
                currentGroupId++;
            }
        }
    }

    return groupGrid;
}

void getGroups(const vector<vector<int>>& groupGrid, const vector<vector<int>>& grid, vector<Group>& groups) {
    const int n = groupGrid.size();

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < n; x++) {
            if(groups[groupGrid[y][x]].originalNumber == -1) {
                groups[groupGrid[y][x]].originalNumber = grid[y][x];
            }

            groups[groupGrid[y][x]].cellCount++;
        }
    }
}

void getBorders(const vector<vector<int>>& groupGrid, vector<vector<int>>& borders) {
    const int n = groupGrid.size();

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < n; x++) {
            int groupId = groupGrid[y][x];

            for(int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];

                if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                    if(groupGrid[ny][nx] != groupId) {
                        borders[groupId][groupGrid[ny][nx]]++;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int currentGroupId = 0;
    vector<vector<int>> groupGrid = getGroupGrid(grid, n, currentGroupId);

    vector<Group> groups(currentGroupId + 1);
    vector<vector<int>> borders(currentGroupId + 1, vector<int>(currentGroupId + 1));

    getGroups(groupGrid, grid, groups);
    getBorders(groupGrid, borders);

    int score = getScore(groups, borders, currentGroupId + 1);
    vector<vector<int>> rotated = grid;

    for(int i = 0; i < 3; i++) {
        currentGroupId = 0;

        rotated = rotate(rotated);
        groupGrid = getGroupGrid(rotated, n, currentGroupId);

        Group g;
        groups.assign(currentGroupId + 1, g);
        borders.assign(currentGroupId + 1, vector<int>(currentGroupId + 1));

        getGroups(groupGrid, rotated, groups);
        getBorders(groupGrid, borders);

        score += getScore(groups, borders, currentGroupId + 1);
    }

    cout << score << "\n";

    return 0;
}