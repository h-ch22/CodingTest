#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

int sum(const vector<vector<int>>& map) {
    int total = 0;

    for (vector<int> m: map) {
        total += accumulate(m.begin(), m.end(), 0);
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, b;
    cin >> n >> m >> b;

    vector<vector<int>> map(n);

    for (int i = 0; i < n; i++) {
        vector<int> v(m);

        for (int j = 0; j < m; j++) {
            cin >> v[j];
        }

        map[i] = v;
    }

    int minTime = numeric_limits<int>::max();
    int maxH = numeric_limits<int>::min();

    for (int h = 0; h <= 256; h++) {
        int tmpBlocks = b;
        int time = 0;

        int sumOfMap = sum(map);

        if ((h * n * m) - sumOfMap > tmpBlocks) {
            continue;
        }

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (map[y][x] > h) {
                    time += 2 * (map[y][x] - h);
                    tmpBlocks += map[y][x] - h;
                } else if (map[y][x] < h) {
                    time += h - map[y][x];
                    tmpBlocks -= map[y][x] - h;
                }
            }
        }

        if (time <= minTime) {
            minTime = time;
            maxH = h;
        }
    }

    cout << minTime << " " << maxH << "\n";

    return 0;
}
