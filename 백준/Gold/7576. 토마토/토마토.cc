#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

const pair<int, int> moves[4] = {
    make_pair(-1, 0), make_pair(1, 0),
    make_pair(0, -1), make_pair(0, 1)
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> box(n, vector<int>(m));
    deque<pair<int, int>> queue;

    for (int i = 0; i < n; i++) {
        vector<int> v(m);

        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;

            v[j] = x;

            if (x == 1) {
                queue.emplace_back(make_pair(i, j));
            }
        }

        box[i] = v;
    }

    if (queue.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    while (!queue.empty()) {
        pair<int, int> current = queue.front();
        int y = current.first;
        int x = current.second;
        queue.pop_front();

        for (int i = 0; i < 4; i++) {
            pair<int, int> move = moves[i];
            int ny = y + move.first;
            int nx = x + move.second;

            if (0 <= ny && ny < n && 0 <= nx && nx < m && box[ny][nx] == 0) {
                box[ny][nx] = box[y][x] + 1;
                queue.emplace_back(make_pair(ny, nx));
            }
        }
    }

    int maxDays = -1;

    for (int y = 0; y < n; y++) {
        if (count(box[y].begin(), box[y].end(), 0) > 0) {
            cout << -1 << "\n";
            return 0;
        }

        maxDays = max(*max_element(box[y].begin(), box[y].end()), maxDays);
    }

    cout << maxDays - 1 << "\n";

    return 0;
}
