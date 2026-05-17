#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int dc[4] = { 0, 1, 0, -1 };
int dr[4] = { -1, 0, 1, 0 };

struct Position {
    int knightId;
    bool isTrap, isWall;

    Position(): knightId(-1), isTrap(false), isWall(false) {}
};

struct Knight {
    // r: 세로, c: 갸로, h: 높이, w: 길이, k: 체력, tempCumulativeDamage: 이동하면서 발생한 임시 데미지, cumulativeDamage: 실제로 받은 누적 데미지
    int id, r, c, h, w, k, tempCumulativeDamage, cumulativeDamage;
    bool isOut;

    Knight(): id(-1), r(0), c(0), h(0), w(0), k(0), tempCumulativeDamage(0), cumulativeDamage(0), isOut(false) {}

    void out(vector<vector<Position>>& grid) {
        isOut = true;
        
        for(int i = r; i < r + h; i++) {
            for(int j = c; j < c + w; j++) {
                grid[i][j].knightId = -1;
            }
        }
    }

    void decreaseK() {
        k -= tempCumulativeDamage;
        cumulativeDamage += tempCumulativeDamage;
        tempCumulativeDamage = 0;
    }

    void increaseDamage(int amount) {
        tempCumulativeDamage += amount;
    }
};

void move(vector<vector<Position>>& grid, vector<Knight>& knights, const int direction, const int target, queue<Knight> toMove) {
    while(!toMove.empty()) {
        Knight current = toMove.front();
        toMove.pop();

        int originalStartR = current.r, originalStartC = current.c;
        int originalEndR = current.r + current.h, originalEndC = current.c + current.w;

        int toStartR = originalStartR + dr[direction], toStartC = originalStartC + dc[direction];
        int toEndR = originalEndR + dr[direction], toEndC = originalEndC + dc[direction];

        // 원래 위치의 기사 제거
        for(int i = originalStartR; i < originalEndR; i++) {
            for(int j = originalStartC; j < originalEndC; j++) {
                grid[i][j].knightId = -1;
            }
        }

        // 새로운 위치에 기사 배정
        knights[current.id].r = toStartR;
        knights[current.id].c = toStartC;

        // 기사에게 데미지는 모두 이동한 후 생기므로 우선 누적 데미지만 올림
        for(int i = toStartR; i < toEndR; i++) {
            for(int j = toStartC; j < toEndC; j++) {
                grid[i][j].knightId = current.id;

                if(grid[i][j].isTrap && current.id != target) {
                    knights[current.id].increaseDamage(1);
                }
            }
        }
    }

    // 모두 성공적으로 이동했을 때 실제 데미지를 기사에게 입힘.
    for(Knight& k: knights) {
        k.decreaseK();

        // 체력이 0 이하일 경우 out 처리
        if(k.k <= 0) {
            k.out(grid);
        }
    }
}

void findTargets(vector<vector<Position>>& grid, vector<Knight>& knights, const int target, const int direction) {
    // 원래 BFS는 Deque을 사용하지만 여기에서는 기사가 움직일 때 움직이려는 칸에 다른 기사가 있으면 그 기사를 우선해서 움직여야하기 때문에 선입후출인 Stack을 사용
    stack<Knight> s;
    queue<Knight> toMove;
    s.push(knights[target]);
    bool isWallDetected = false;

    vector<bool> isPushed(knights.size(), false);
    isPushed[target] = true;

    const int l = grid.size();

    while(!s.empty()) {
        if(isWallDetected) {
            return;
        }

        Knight current = s.top();

        int originalStartR = current.r, originalStartC = current.c;
        int originalEndR = current.r + current.h, originalEndC = current.c + current.w;

        int toStartR = originalStartR + dr[direction], toStartC = originalStartC + dc[direction];
        int toEndR = originalEndR + dr[direction], toEndC = originalEndC + dc[direction];

        bool isAnotherKnightDetected = false;

        // 체스판 밖이면 flag (toEndR, toEndC: toStart부터 toEnd - 1까지이기 때문에 toEndR, toEndC는 l과 같을 수 있다.)
        if(toStartR < 0 || toStartC < 0 || toEndR < 0 || toEndC < 0 || toStartR >= l || toStartC >= l || toEndR > l || toEndC > l) {
            isWallDetected = true;
            continue;
        }

        for(int i = toStartR; i < toEndR; i++) {
            for(int j = toStartC; j < toEndC; j++) {
                // 벽이면 flag
                if(grid[i][j].isWall) {
                    isWallDetected = true;
                }

                // 다른 기사가 있고, 해당 기사의 id가 움직이려는 기사의 id가 아니고, 중복되지 않았을 때 flag
                if(grid[i][j].knightId > -1 && !isPushed[grid[i][j].knightId]) {
                    isAnotherKnightDetected = true;
                    s.push(knights[grid[i][j].knightId]);
                    isPushed[grid[i][j].knightId] = true;
                }
            }
        }

        // 다른 기사가 감지된 경우 해당 기사를 우선 이동하고, 벽이 감지된 경우 continue를 통해 자연스럽게 break되도록 설정
        if(isAnotherKnightDetected || isWallDetected) {
            continue;
        }

        toMove.push(current);

        // 만약에 다른 기사가 발견된 경우 현재 기사 위에 다른 기사가 올라와야하기 때문에 pop을 나중에 한다.
        s.pop();
    }

    // 실제 이동
    move(grid, knights, direction, target, toMove);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, n, q;
    cin >> l >> n >> q;

    // 0: 빈 칸, 1: 함정, 2: 벽
    vector<vector<Position>> grid(l, vector<Position>(l));
    vector<Knight> knights(n);

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < l; j++) {
            int env;
            cin >> env;

            if(env == 1) {
                grid[i][j].isTrap = true;
            } else if(env == 2) {
                grid[i][j].isWall = true;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        Knight knight;
        knight.id = i;
        cin >> knight.r >> knight.c >> knight.h >> knight.w >> knight.k;

        knight.r -= 1;
        knight.c -= 1;
        knights[i] = knight;
        
        for(int j = knight.r; j < knight.r + knight.h; j++) {
            for(int k = knight.c; k < knight.c + knight.w; k++) {
                grid[j][k].knightId = i;
            }
        }
    }

    while(q--) {
        // 0: 상, 1: 우, 2: 하, 3: 좌
        int knightId, direction;
        cin >> knightId >> direction;

        // 사라진 기사인 경우 pass
        if(knights[knightId - 1].isOut) {
            continue;
        }

        findTargets(grid, knights, knightId - 1, direction);
    }

    int damages = 0;

    for(const Knight& k: knights) {
        if(!k.isOut) {
            damages += k.cumulativeDamage;
        }
    }

    cout << damages << "\n";

    return 0;
}