#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int k, m;
vector<vector<int>> grid(5, vector<int>(5));
queue<int> nums;

const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };

struct ScoreAndCoords {
    int score;
    vector<pair<int, int>> coords;

    ScoreAndCoords(): score(0) {}
};

// r: 세로, c: 가로
void rotate(vector<vector<int>>& target, const int r, const int c, const int degree) {
    vector<vector<int>> tmp(3, vector<int>(3));
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i + r < 5 && j + c < 5) {
                if(degree == 90) {
                    tmp[j][2 - i] = grid[i + r][j + c];
                } else if(degree == 180) {
                    tmp[2 - i][2 - j] = grid[i + r][j + c];
                } else {
                    tmp[2 - j][i] = grid[i + r][j + c];
                }
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i + r < 5 && j + c < 5) {
                target[i + r][j + c] = tmp[i][j];
            }
        }
    }
}

ScoreAndCoords bfs(vector<vector<int>>& target, const int r, const int c, vector<vector<bool>>& visited) {
    int targetNum = target[r][c];

    deque<pair<int, int>> q;
    q.emplace_back(r, c);

    visited[r][c] = true;

    vector<pair<int, int>> toChange;
    toChange.emplace_back(r, c);

    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop_front();

        for(int i = 0; i < 4; i++) {
            int nr = current.first + dr[i];
            int nc = current.second + dc[i];

            if(0 <= nr && nr < 5 && 0 <= nc && nc < 5 && !visited[nr][nc] && target[nr][nc] == targetNum) {
                visited[nr][nc] = true;
                toChange.emplace_back(nr, nc);
                q.emplace_back(nr, nc);
            }
        }
    }

    ScoreAndCoords result;

    if(toChange.size() >= 3) {
        result.score += toChange.size();
        result.coords = toChange;
        
        for(const pair<int, int> t: toChange) {
            target[t.first][t.second] = 0;
        }
    }

    return result;
}

ScoreAndCoords getScore(vector<vector<int>>& target) {
    ScoreAndCoords result;
    vector<vector<bool>> visited(5, vector<bool>(5));

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(target[i][j] != 0 && !visited[i][j]) {
                ScoreAndCoords r = bfs(target, i, j, visited);

                if(r.score > 0) {
                    result.score += r.score;
                    result.coords.insert(result.coords.end(), r.coords.begin(), r.coords.end());
                }
            }
        }
    }

    return result;
}

void fill(vector<pair<int, int>>& target) {
    sort(target.begin(), target.end(), [](const pair<int, int> a, const pair<int, int> b){
        if(a.second == b.second) {
            return a.first > b.first;
        }

        return a.second < b.second;
    });

    for(const pair<int, int> t: target) {
        grid[t.first][t.second] = nums.front();
        nums.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> m;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;

        nums.push(num);
    }

    while(k--) {
        // 1. 회전하기 (작은 각도 -> 작은 열 -> 작은 행)
        ScoreAndCoords bestResult;
        bestResult.score = -1;

        vector<vector<int>> bestGrid = grid;

        for(const int degree: { 90, 180, 270 }) {
            // rotate 함수에 5보다 작을 때 버리는 로직이 있지만 그렇다고 i < 5 , j < 5로 해버리면 3x3이 아닌 크기가 회전될 수 있기 때문에 여기서 수치를 조정함
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    vector<vector<int>> gridCopy = grid;
                    rotate(gridCopy, j, i, degree);

                    ScoreAndCoords result = getScore(gridCopy);
                    
                    if(result.score > bestResult.score) {
                        bestResult = result;
                        bestGrid = gridCopy;
                    }
                }
            }
        }

        // 아무 것도 획득하지 못했으면 바로 종료
        if(bestResult.score <= 0) {
            break;
        }

        // bestGrid로 업데이트 후 채우기
        grid = bestGrid;
        fill(bestResult.coords);

        // 연쇄 유물 획득
        while(true) {
            ScoreAndCoords result = getScore(grid);

            if(result.score == 0) {
                cout << bestResult.score << " ";
                break;
            }

            bestResult.score += result.score;
            fill(result.coords);
        }
    }

    return 0;
}