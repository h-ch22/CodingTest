#include <iostream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct State {
    int x;
    int y;
    bool isBroken;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(2, false)));

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++) {
            grid[i][j] = input[j] - '0';
        }
    }

    deque<State> queue;
    queue.emplace_back(State { 0, 0, false });
    visited[0][0][0] = 1;

    while (!queue.empty()) {
        const State current = queue.front();
        queue.pop_front();

        if (current.x == m - 1 && current.y == n - 1) {
            cout << visited[current.y][current.x][current.isBroken] << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            const int nx = current.x + dx[i];
            const int ny = current.y + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                if (grid[ny][nx] == 1 && !current.isBroken) {
                    visited[ny][nx][true] = visited[current.y][current.x][current.isBroken] + 1;
                    queue.emplace_back(State { nx, ny, true });
                } else if (grid[ny][nx] == 0 && !visited[ny][nx][current.isBroken]) {
                    visited[ny][nx][current.isBroken] = visited[current.y][current.x][current.isBroken] + 1;
                    queue.emplace_back(State { nx, ny, current.isBroken });
                }
            }
        }
    }
    
    cout << -1 << "\n";

    return 0;
}
