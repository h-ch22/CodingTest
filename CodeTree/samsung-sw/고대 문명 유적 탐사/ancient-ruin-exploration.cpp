#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define GRID_SIZE 5

using namespace std;

struct ScoreAndTrace {
    int score;
    vector<pair<int, int>> trace;
};

int k, m;
vector<vector<int>> grid(GRID_SIZE, vector<int>(GRID_SIZE));
deque<int> nums;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

vector<vector<int>> rotate(const int startR, const int startC, const int degree) {
    int tmp[3][3];
    vector<vector<int>> gridCopy = grid;

    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            if(degree == 90) {
                tmp[c][3 - 1 - r] = grid[startR + r][startC + c];
            } else if(degree == 180) {
                tmp[3 - 1 - r][3 - 1 - c] = grid[startR + r][startC + c];
            } else {
                tmp[3 - 1 - c][r] = grid[startR + r][startC + c];
            }
        }
    }

    for(int r = 0; r < 3; r++) {
        for(int c = 0; c < 3; c++) {
            gridCopy[startR + r][startC + c] = tmp[r][c];
        }
    }

    return gridCopy;
}

ScoreAndTrace collect(vector<vector<int>>& g, int startR, int startC) {
    int score = 0;
    deque<pair<int, int>> queue;
    vector<vector<bool>> visited(GRID_SIZE, vector<bool>(GRID_SIZE));
    vector<pair<int, int>> trace;

    queue.emplace_back(startR, startC);
    visited[startR][startC] = true;
    trace.emplace_back(startR, startC);

    int target = g[startR][startC];

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        const int r = current.first, c = current.second;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];

            if(0 <= nr && nr < GRID_SIZE && 0 <= nc && nc < GRID_SIZE && !visited[nr][nc] && g[nr][nc] == target) {
                queue.emplace_back(nr, nc);
                trace.emplace_back(nr, nc);
                visited[nr][nc] = true;
            }
        }
    }

    if(trace.size() >= 3) {
        score = trace.size();

        for(const pair<int, int> t: trace) {
            g[t.first][t.second] = 0;
        }
    } else {
        trace.clear();
    }

    return { score, trace };
}

ScoreAndTrace getScore(vector<vector<int>>& g) {
    ScoreAndTrace result;
    result.score = 0;

    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(g[i][j] != 0) {
                ScoreAndTrace r = collect(g, i, j);
                result.trace.insert(result.trace.end(), r.trace.begin(), r.trace.end());
                result.score += r.score;
            }
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> m;
    
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;

        nums.emplace_back(num);
    }

    while(k--) {
        int maxValue = -1;
        int degree = 270;

        vector<pair<int, int>> trace;
        vector<vector<int>> bestGrid;

        for(const int d: {90, 180, 270}) {
            for(int j = 0; j < GRID_SIZE - 2; j++) {
                for(int i = 0; i < GRID_SIZE - 2; i++) {
                    vector<vector<int>> rotated = rotate(i, j, d);
                    ScoreAndTrace result = getScore(rotated);

                    if(
                        result.score > maxValue ||
                        (result.score == maxValue && d < degree)
                    ) {
                        maxValue = result.score;
                        degree = d;
                        bestGrid = rotated;
                        trace = result.trace;
                    }
                }
            }
        }

        grid = bestGrid;

        if(trace.size() == 0) {
            break;
        }

        while(true) {
            sort(trace.begin(), trace.end(), [](const pair<int, int> a, const pair<int, int> b){
                if(a.second == b.second) {
                    return a.first > b.first;
                }

                return a.second < b.second;
            });

            for(int i = 0; i < trace.size(); i++) {
                const pair<int, int> target = trace[i];

                int newRelic = nums.front();
                nums.pop_front();

                grid[target.first][target.second] = newRelic;
            }

            ScoreAndTrace chainScore = getScore(grid);

            maxValue += chainScore.score;
            trace = chainScore.trace;

            if(chainScore.score == 0) {
                cout << maxValue << " ";
                break;
            }
        }
    }

    cout << "\n";

    return 0;
}
