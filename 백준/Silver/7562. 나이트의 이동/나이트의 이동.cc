#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const pair<int, int> directions[8] = {
    make_pair(-2, 1), make_pair(-2, -1), make_pair(-1, 2), make_pair(-1, -2),
    make_pair(1, 2), make_pair(1, -2), make_pair(2, 1), make_pair(2, -1)
};

void bfs(vector<vector<int>>& board, const pair<int, int>& current, const pair<int, int>& destination) {
    deque<pair<int, int>> queue;
    queue.emplace_back(current);

    while (!queue.empty()) {
        pair<int, int> currentPos = queue.front();
        queue.pop_front();

        if (currentPos == destination) {
            cout << board[currentPos.first][currentPos.second] - 1 << "\n";
            break;
        }

        int y = currentPos.first;
        int x = currentPos.second;

        for (int i = 0; i < 8; i++) {
            int ny = y + directions[i].first;
            int nx = x + directions[i].second;

            if (0 <= nx && nx < board.size() && 0 <= ny && ny < board.size()) {
                if (board[ny][nx] == 0) {
                    board[ny][nx] = board[y][x] + 1;
                    queue.emplace_back(make_pair(ny, nx));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int l;
        cin >> l;

        vector<vector<int>> board(l, vector<int>(l));
        pair<int, int> currentPos;
        pair<int, int> destPos;

        for (int i = 0; i < 2; i++) {
            int x, y;
            cin >> x >> y;

            if (i == 0) {
                currentPos.first = y;
                currentPos.second = x;
                board[y][x] = 1;
            } else {
                destPos.first = y;
                destPos.second = x;
            }
        }

        bfs(board, currentPos, destPos);
    }

    return 0;
}
