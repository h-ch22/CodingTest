#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

struct Tomato {
    int x, y, z;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> box(h);
    deque<Tomato> queue;

    for (int i = 0; i < h; i++) {
        vector<vector<int>> currentFloor(n);

        for (int j = 0; j < n; j++) {
            vector<int> tomatoes(m);

            for (int k = 0; k < m; k++) {
                int t;
                cin >> t;

                if (t == 1) {
                    queue.emplace_back(Tomato{ k, j, i });
                }

                tomatoes[k] = t;
            }

            currentFloor[j] = tomatoes;
        }

        box[i] = currentFloor;
    }

    if (queue.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    while (!queue.empty()) {
        const Tomato target = queue.front();
        queue.pop_front();

        for (int i = 0; i < 6; i++) {
            const int nx = target.x + dx[i];
            const int ny = target.y + dy[i];
            const int nz = target.z + dz[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h) {
                if (box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = box[target.z][target.y][target.x] + 1;
                    queue.emplace_back(Tomato{ nx, ny, nz });
                }
            }
        }
    }

    int maxDays = -1;

    for (const vector<vector<int>>& floor: box) {
        for (const vector<int>& row: floor) {
            if (count(row.begin(), row.end(), 0) > 0) {
                cout << -1 << "\n";
                return 0;
            }

            maxDays = max(maxDays, *max_element(row.begin(), row.end()));
        }
    }

    cout << maxDays - 1 << "\n";

    return 0;
}
