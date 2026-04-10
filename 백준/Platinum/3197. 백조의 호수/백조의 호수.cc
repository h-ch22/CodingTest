#include <iostream>
#include <vector>
#include <deque>

using namespace std;

constexpr int dx[4] = { -1, 1, 0, 0 };
constexpr int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));

    deque<pair<int, int>> swanQueue;
    deque<pair<int, int>> nextSwanQueue;
    deque<pair<int, int>> waterQueue;
    deque<pair<int, int>> nextWaterQueue;

    vector<vector<bool>> swanVisited(r, vector<bool>(c));
    vector<vector<bool>> waterVisited(r, vector<bool>(c));

    pair<int, int> swan1 = { -1, -1 };
    pair<int, int> swan2 = { -1, -1 };

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            char ch;
            cin >> ch;
            grid[y][x] = ch;

            if (ch == '.') {
                waterQueue.emplace_back(make_pair(y, x));
                waterVisited[y][x] = true;
            } else if (ch == 'L') {
                if (swan1.first == -1 && swan1.second == -1) {
                    swan1 = { y, x };
                    swanQueue.emplace_back(make_pair(y, x));
                    swanVisited[y][x] = true;
                } else {
                    swan2 = { y, x };
                }

                waterQueue.emplace_back(make_pair(y, x));
                waterVisited[y][x] = true;
            }
        }
    }

    int days = 0;

    while (true) {
        while (!swanQueue.empty()) {
            const pair<int, int> current = swanQueue.front();
            swanQueue.pop_front();

            for (int i = 0; i < 4; i++) {
                const int ny = current.first + dy[i];
                const int nx = current.second + dx[i];

                if (0 <= ny && ny < r && 0 <= nx && nx < c && !swanVisited[ny][nx]) {
                    swanVisited[ny][nx] = true;

                    if (ny == swan2.first && nx == swan2.second) {
                        cout << days << "\n";
                        return 0;
                    }

                    if (grid[ny][nx] == '.') {
                        swanQueue.emplace_back(make_pair(ny, nx));
                    } else if (grid[ny][nx] == 'X') {
                        nextSwanQueue.emplace_back(make_pair(ny, nx));
                    }
                }
            }
        }

        swanQueue = nextSwanQueue;
        nextSwanQueue.clear();

        while (!waterQueue.empty()) {
            const pair<int, int> current = waterQueue.front();
            waterQueue.pop_front();

            for (int i = 0; i < 4; i++) {
                int ny = current.first + dy[i];
                int nx = current.second + dx[i];

                if (0 <= ny && ny < r && 0 <= nx && nx < c && !waterVisited[ny][nx]) {
                    waterVisited[ny][nx] = true;

                    if (grid[ny][nx] == '.') {
                        waterQueue.emplace_back(make_pair(ny, nx));
                    } else if (grid[ny][nx] == 'X') {
                        nextWaterQueue.emplace_back(make_pair(ny, nx));
                    }
                }
            }
        }

        waterQueue = nextWaterQueue;

        while (!nextWaterQueue.empty()) {
            pair<int, int> current = nextWaterQueue.front();
            nextWaterQueue.pop_front();

            grid[current.first][current.second] = '.';
        }

        days++;
    }
}
