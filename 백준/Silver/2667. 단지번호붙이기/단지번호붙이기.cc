#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };

void dfs(vector<string>& grid, const int x, const int y, int& count) {
    grid[y][x] = '2';
    count++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size()) {
            if (grid[ny][nx] == '1') {
                dfs(grid, nx, ny, count);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sections = 0;

    vector<string> grid(n);
    vector<int> counts;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (grid[y][x] == '1') {
                sections++;
                int cnt = 0;

                dfs(grid, x, y, cnt);
                counts.emplace_back(cnt);
            }
        }
    }

    cout << sections << "\n";

    sort(counts.begin(), counts.end());

    for (int c: counts) {
        if (c > 0) {
            cout << c << "\n";
        }
    }

    return 0;
}
