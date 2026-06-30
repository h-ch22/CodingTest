#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct Golem;
int r, c, k, answer;
vector<vector<int>> grid;
vector<vector<bool>> exitList;
vector<Golem> golems;

const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };

struct Golem {
    int id, r, c, d;
    
    Golem() {}
    Golem(const int id, const int c, const int d) {
        this->id = id;
        this->c = c;
        this->d = d;

        r = 0;
    }

    void applyToGrid() {
        // grid에 현재 id를 골렘의 영역만큼 칠한 후 exit에 현재 출구 방향에 따라 마킹
        grid[r][c] = id;
        
        for(int i = 0; i < 4; i++) {
            const int nr = r + dr[i], nc = c + dc[i];

            grid[nr][nc] = id;
        }
        
        switch(d) {
            case 0:
                exitList[r - 1][c] = true;
                break;
            
            case 1:
                exitList[r][c + 1] = true;
                break;

            case 2:
                exitList[r + 1][c] = true;
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

bool canMoveDown(const int r, const int c) {
    const int toR = r + 1, toC = c; // r에 +1해서 아래로 한 칸 내림 (c는 변함 X)

    if(toR >= ::r) return false; // 1. 가려는 지점(가운데 기준)이 범위를 초과하는 경우 false

    // 2. 가운데를 제외한 골렘의 부분을 확인한다.
    for(int i = 0; i < 4; i++) {
        const int nr = toR + dr[i], nc = toC + dc[i];

        if(0 <= nr && nr < ::r && 0 <= nc && nc < ::c) {
            if(grid[nr][nc] > -1) {
                return false; // 3. grid의 해당 부분이 빈 칸이 아닌 경우 false
            }
        } else {
            return false; // 2. 몸통 부분이 범위를 초과하는 경우 false
        }
    }

    return true; // 위 사항을 모두 만족하는 경우 true
}

bool canRotateLeftAndDown(const int r, const int c) {
    const int toR = r, toC = c - 1; // r은 그대로, c는 한 칸 왼쪽으로 이동한다.

    if(toC >= ::c || toC < 0) return false;

    for(int i = 0; i < 4; i++) {
        const int nr = toR + dr[i], nc = toC + dc[i];

        if(0 <= nr && nr < ::r && 0 <= nc && nc < ::c) {
            if(grid[nr][nc] > -1) {
                return false;
            }
        } else {
            return false;
        }
    }

    return canMoveDown(toR, toC); // canMoveDown 호출로 위에서 회전할 수 있다고 판단되는 경우 아래로 내려갈 수 있는지 확인한 결과를 return
}

bool canRotateRightAndDown(const int r, const int c) {
    const int toR = r, toC = c + 1; // r은 그대로, c는 한 칸 오른쪽으로 이동한다.

    if(toC >= ::c || toC < 0) return false;

    for(int i = 0; i < 4; i++) {
        const int nr = toR + dr[i], nc = toC + dc[i];

        if(0 <= nr && nr < ::r && 0 <= nc && nc < ::c) {
            if(grid[nr][nc] > -1) {
                return false;
            }
        } else {
            return false;
        }
    }

    return canMoveDown(toR, toC);
}

void bfs(const Golem& golem) {
    deque<pair<int, int>> queue;
    vector<vector<bool>> visited(r, vector<bool>(c));

    queue.emplace_back(golem.r, golem.c);
    visited[golem.r][golem.c] = true;

    int maxR = -1;

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        const int r = current.first, c = current.second;
        maxR = max(r, maxR); // queue에서 꺼내자마자 (어차피 이 곳은 간 곳이기 때문에 무방) 갱신해주면 조기 종료가 가능해진다.

        if(maxR == ::r - 1) {
            break; // 정령이 제일 아래(r - 1)까지 내려왔다면 더 이상 BFS를 진행할 이유가 없다.
        }

        for(int i = 0; i < 4; i++) {
            const int nr = r + dr[i], nc = c + dc[i];

            if(0 <= nr && nr < ::r && 0 <= nc && nc < ::c && !visited[nr][nc]) {
                // 새로갈 위치가 현재 위치의 id와 동일(현재 golem 내부)하거나, 이전 위치가 출구(현재 위치가 golem 내부가 아니더라도)이고, 현재 위치가 어느 골렘 안인 경우 계속 진행한다.
                if(grid[nr][nc] == grid[r][c] || (exitList[r][c] && grid[nr][nc] > -1)) {
                    visited[nr][nc] = true; // 일반적인 BFS는 방문하자마자 범위만 확인하고 visited를 true로 바꾸지만, 이 문제는 정령이 이동하는 것으로, 동일한 위치이더라도 이전 위치가 exit였는지, 아니였는지에 따라 다음 상태가 정해지고, 따라서 같은 위치에 여러번 방문할 수 있다.
                    queue.emplace_back(nr, nc);
                }
            }
        }
    }

    answer += (maxR - 2); // padding만큼 빼주기 (2를 빼주는 이유는 정령이 내려오기 전에는 완전체 (3열)가 grid 바깥에 있지만 모두 내려온 경우에는 아래에 1칸 (몸통 아래)이 존재하기 때문에 정령이 몸통 위치 기준 1칸 아래로 내려갈 수 있다.)
}

void move(Golem& golem) {
    while(true) {
        if(canMoveDown(golem.r, golem.c)) {
            golem.r += 1;
            continue;
        }

        if(canRotateLeftAndDown(golem.r, golem.c)) {
            golem.r += 1;
            golem.c -= 1;
            golem.d = (golem.d + 3) % 4; // 반시계 방향 회전은 -1을 해줘야하지만, 그렇게 되면 modulo 연산 과정에서 음수가 나올 수 있어 -1과 동일한 3칸 시계 방향 이동으로 처리 후 modulo 연산을 한다.

            continue;
        }

        if(canRotateRightAndDown(golem.r, golem.c)) {
            golem.r += 1;
            golem.c += 1;
            golem.d = (golem.d + 1) % 4; // 시계 방향 회전은 +1과 동일하다. 이후 modulo 연산을 진행해 0-3 사이에 갇히도록 만든다.
            continue;
        }

        break; // 다 움직였으면 break
    }

    // golem.r, c는 중앙 기준이므로, golem 자체가 모두 내려온 것은 중앙이 4 (위에 한 칸 있으니까) 이상일 때임.
    if(golem.r >= 4) {
        golem.applyToGrid(); // 다 내려왔으면 apply
        bfs(golem); // 정령의 이동 시작
    } else {
        resetGrid(); // 그렇지 않으면 grid를 reset한다.
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> k;

    r += 3; // Padding (0-2)
    grid.assign(r, vector<int>(c, -1));
    exitList.assign(r, vector<bool>(c));

    for(int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;

        Golem currentGolem = Golem(i, --c, d);
        move(currentGolem);
        golems.emplace_back(currentGolem);
    }

    cout << answer << "\n";

    return 0;
}