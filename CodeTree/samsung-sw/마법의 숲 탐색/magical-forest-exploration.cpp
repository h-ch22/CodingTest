#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct Golem;

int r, c, k, answer;
vector<vector<int>> grid;
vector<vector<bool>> exitList;
vector<Golem> golems;

const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, -1, 0, 1 };

struct Golem {
    int id, r, c, d; // 0: 북, 1: 동, 2: 남, 3: 서

    Golem() {}
    Golem(const int id, const int c, const int d) {
        this->id = id;
        this->c = c;
        this->d = d;
        r = 0;
    }

    void move(const int r, const int c) {
        this->r = r;
        this->c = c;
    }

    void rotateAndMove(const int r, const int c, const int d) {
        this->r = r;
        this->c = c;
        this->d = d;
    }

    void applyToGrid() {
        grid[r][c] = id;

        for(int i = 0; i < 4; i++) {
            grid[r + dr[i]][c + dc[i]] = id;
        }

        // 출구 좌표 저장
        switch(d) {
            case 0:
                exitList[r - 1][c] = true;
                break;

            case 1:
                exitList[r][c + 1] = true;
                break;

            case 2:
                exitList[r + 1][c] =  true;
                break;

            case 3:
                exitList[r][c - 1] = true;
                break;

            default: break;
        }
    }
};

void resetGrid() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            grid[i][j] = -1;
            exitList[i][j] = false;
        }
    }
}

// 정령의 이동
void bfs(const Golem& golem) {
    deque<pair<int, int>> queue; // first: 출구로 나왔는지 여부, second - third: 좌표
    vector<vector<bool>> visited(r, vector<bool>(c));

    queue.emplace_back(golem.r, golem.c);
    visited[golem.r][golem.c] = true;

    int maxRow = -1;

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        maxRow = max(maxRow, current.first);

        for(int i = 0; i < 4; i++) {
            const int nr = current.first + dr[i], nc = current.second + dc[i];

            if(0 <= nr && nr < r && 0 <= nc && nc < c && !visited[nr][nc] && grid[nr][nc] > -1) {  
                // grid의 현재 위치가 새 위치의 ID(골렘)와 같을 때 또는 현재 위치가 출구일 때 (출구이면 어차피 이동할 수 있고, 새 위치가 골렘 영역 밖인 경우는 위에서 컷 당하니까)              
                if(grid[nr][nc] == grid[current.first][current.second] || exitList[current.first][current.second]) {
                    visited[nr][nc] = true;
                    queue.emplace_back(nr, nc);
                }
            }
        }
    }

    if(maxRow > -1) {
        answer += (maxRow - 2);
    }
}

// 현재 칸에서 한 칸 내려갈 수 있는지 확인
bool canGoDown(const int r, const int c) {
    // 범위 초과
    if(r < 0 || r >= ::r) return false;
    if(c < 0 || c >= ::c) return false;

    // 중심을 기준으로 한 칸 바로 아래가 비어있지 않다면 return false
    if(grid[r][c] > -1) return false;

    for(int i = 0; i < 4; i++) {
        const int nr = r + dr[i], nc = c + dc[i];

        if(nr < 0 || nr >= ::r || nc < 0 || nc >= :: c) return false;
        if(grid[nr][nc] > -1) return false;
    }

    return true;
}

// 현재 칸에서 왼쪽으로 회전 후 한 칸 내려갈 수 있는지 확인
bool canRotateLeftAndDown(const int r, const int c, const int d) {
    // 범위 초과
    if(r < 0 || r >= ::r) return false;
    if(c < 0 || c >= ::c) return false;

    if(grid[r][c] > -1) return false; // 중앙

    for(int i = 0; i < 4; i++) {
        const int nr = r + dr[i], nc = c + dc[i];

        if(nr < 0 || nr >= ::r || nc < 0 || nc >= :: c) return false;
        if(grid[nr][nc] > -1) return false;
    }
    
    return canGoDown(r + 1, c);
}

// 현재 칸에서 오른쪽으로 회전 후 한 칸 내려갈 수 있는지 확인
bool canRotateRightAndDown(const int r, const int c, const int d) {
    // 범위 초과
    if(r < 0 || r >= ::r) return false;
    if(c < 0 || c >= ::c) return false;

    if(grid[r][c] > -1) return false; // 중앙

    for(int i = 0; i < 4; i++) {
        const int nr = r + dr[i], nc = c + dc[i];

        if(nr < 0 || nr >= ::r || nc < 0 || nc >= :: c) return false;
        if(grid[nr][nc] > -1) return false;
    }

    return canGoDown(r + 1, c);
}

void move(Golem& golem) {
    while(true) {
        if(canGoDown(golem.r + 1, golem.c)) {
            golem.move(golem.r + 1, golem.c);
            continue;
        }

        const int rotatedLeft = (golem.d + 3) % 4;
        const int rotatedRight = (golem.d + 1) % 4;

        if(canRotateLeftAndDown(golem.r, golem.c - 1, rotatedLeft)) {
            golem.rotateAndMove(golem.r + 1, golem.c - 1, rotatedLeft);
            continue;
        }

        if(canRotateRightAndDown(golem.r, golem.c + 1, rotatedRight)) {
            golem.rotateAndMove(golem.r + 1, golem.c + 1, rotatedRight);
            continue;
        }

        // 더 이상 움직일 수 없는 경우

        // 그리드에 접근조차 못했을 때 리셋
        if(golem.r < 4) {
            resetGrid();
            break;
        }

        // 골렘의 현재 좌표를 Grid에 적용
        golem.applyToGrid();
        bfs(golem);
        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> k;
    answer = 0;
    r += 3; // Padding (0-2)

    grid.assign(r, vector<int>(c, -1));
    exitList.assign(r, vector<bool>(c, false));
    
    for(int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;

        c--;
        golems.emplace_back(Golem(i, c, d));
        move(golems.back());
    }

    cout << answer << "\n";

    return 0;
}