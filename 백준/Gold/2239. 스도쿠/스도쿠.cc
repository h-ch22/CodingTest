#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool validate(const int y, const int x, const int num, const vector<vector<int>>& grid) {
    if (count(grid[y].begin(), grid[y].end(), num) > 0) {
        return false;
    }

    for (int i = 0; i < 9; i++) {
        if (grid[i][x] == num) {
            return false;
        }
    }

    int topLeftY = (y / 3) * 3;
    int topLeftX = (x / 3) * 3;

    for (int i = topLeftY; i < topLeftY + 3; i++) {
        for (int j = topLeftX; j < topLeftX + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

void dfs(const int idx, vector<vector<int>>& grid, const vector<pair<int, int>>& blanks) {
    if (idx == blanks.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << grid[i][j];
            }

            cout << "\n";
        }

        exit(0);
    }

    const int y = blanks[idx].first;
    const int x = blanks[idx].second;

    if (grid[y][x] != 0) {
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (validate(y, x, i, grid)) {
            grid[y][x] = i;
            dfs(idx + 1, grid, blanks);
            grid[y][x] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid(9, vector<int>(9));
    vector<pair<int, int>> blanks;

    for (int i = 0; i < 9; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < 9; j++) {
            grid[i][j] = row[j] - '0';

            if (row[j] == '0') {
                blanks.emplace_back(make_pair(i, j));
            }
        }
    }

    dfs(0, grid, blanks);

    return 0;
}
