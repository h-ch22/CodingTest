#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct State {
    int rx, ry, bx, by, depth;
};

void move(int& x, int &y, const int nx, const int ny, int& dist, vector<string>& grid) {
    while (grid[y + ny][x + nx] != '#') {
        x += nx;
        y += ny;
        dist++;

        if (grid[y][x] == 'O') {
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    pair<int, int> posR, posB;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid[i] = s;

        if (s.find('R') != string::npos) {
            posR.first = i;
            posR.second = static_cast<int>(s.find('R'));
        }

        if (s.find('B') != string::npos) {
            posB.first = i;
            posB.second = static_cast<int>(s.find('B'));
        }
    }

    deque<State> queue;
    vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(n, vector<bool>(m))));

    queue.emplace_back(State({posR.second, posR.first, posB.second, posB.first, 0}));
    visited[posR.first][posR.second][posB.first][posB.second] = true;

    while (!queue.empty()) {
        State current = queue.front();
        queue.pop_front();

        if (current.depth >= 10) {
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nRx = current.rx;
            int nRy = current.ry;
            int nBx = current.bx;
            int nBy = current.by;

            int rDist = 0;
            int bDist = 0;

            move(nRx, nRy, dx[i], dy[i], rDist, grid);
            move(nBx, nBy, dx[i], dy[i], bDist, grid);

            if (nRx == nBx && nRy == nBy) {
                if (grid[nBy][nBx] != 'O') {
                    if (rDist > bDist) {
                        nRx -= dx[i];
                        nRy -= dy[i];
                    } else {
                        nBx -= dx[i];
                        nBy -= dy[i];
                    }
                }
            }

            if (grid[nBy][nBx] == 'O' && grid[nRy][nRx] == 'O') {
                continue;
            }

            if (grid[nBy][nBx] == 'O') {
                continue;
            }

            if (grid[nRy][nRx] == 'O') {
                cout << current.depth + 1 << "\n";
                return 0;
            }

            if (!visited[nRy][nRx][nBy][nBx]) {
                queue.emplace_back(State({
                    nRx, nRy, nBx, nBy, current.depth + 1
                }));

                visited[nRy][nRx][nBy][nBx] = true;
            }
        }
    }

    cout << -1 << "\n";

    return 0;
}
