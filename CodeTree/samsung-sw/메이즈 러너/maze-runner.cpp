#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Participant;
int n, m, k, exitR, exitC; // r: 세로 (열), c: 가로 (행)

vector<vector<int>> grid; // 0: 빈 칸, 1~: 내구도
vector<Participant> participants;

const int dr[4] = { -1, 1, 0, 0 };
const int dc[4] = { 0, 0, -1, 1 };

struct Participant {
    int r, c, moveCount;
    bool isExit;

    Participant(int r, int c) {
        this->r = r;
        this->c = c;
        isExit = false;
        moveCount = 0;
    }

    void move(int r, int c, bool updateCount) {
        if(isExit) return;

        if(updateCount) {
            moveCount++;
        }

        this->r = r;
        this->c = c;

        if(r == exitR && c == exitC) {
            isExit = true;
        }
    }
};

struct RotateCandidate {
    int r, c, size;

    RotateCandidate(int r, int c, int size) {
        this->r = r;
        this->c = c;
        this->size = size;
    }
};

int getDistance(const int r1, const int r2, const int c1, const int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

bool checkAllParticipantsExit() {
    for(const Participant& p: participants) {
        if(!p.isExit) {
            return false;
        }
    }

    return true;
}

int getAllMoveCount() {
    int total = 0;
    
    for(const Participant& p: participants) {
        total += p.moveCount;
    }

    return total;
}

void move() {
    for(Participant& p: participants) {
        if(p.isExit) continue;

        const int originDistance = getDistance(p.r, exitR, p.c, exitC);

        for(int i = 0; i < 4; i++) {
            const int nr = p.r + dr[i];
            const int nc = p.c + dc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(grid[nr][nc] > 0) continue;

                const int distance = getDistance(nr, exitR, nc, exitC);

                if(distance < originDistance) {
                    p.move(nr, nc, true);
                    break;
                }
            }
        }
    }
}

bool isParticipantExists(const int startR, const int startC, const int endR, const int endC) {
    for(const Participant& p: participants) {
        if(p.isExit) continue;

        if(startR <= p.r && p.r <= endR && startC <= p.c && p.c <= endC) {
            return true;
        }
    }

    return false;
}

RotateCandidate getRect() {
    for(int size = 2; size <= n; size++) {
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                const int startR = r, startC = c;
                const int endR = r + size - 1, endC = c + size - 1;

                // 범위 초과
                if(n <= endR || n <= endC) {
                    continue;
                }

                // 출구가 포함되어 있을 때 계속
                if(startR <= exitR && exitR <= endR && startC <= exitC && exitC <= endC) {
                    // 참가자가 포함되어 있지 않은 경우 skip
                    if(!isParticipantExists(startR, startC, endR, endC)) {
                        continue;
                    }

                    return RotateCandidate(r, c, size);
                }
            }
        }
    }

    return RotateCandidate(-1, -1, -1);
}

void rotate(const RotateCandidate& rect) {
    const int startR = rect.r, startC = rect.c;
    const int endR = rect.r + rect.size, endC = rect.c + rect.size;
    int newExitR = exitR, newExitC = exitC;

    vector<vector<int>> tmp(rect.size, vector<int>(rect.size));

    for(int i = startR; i < endR; i++) {
        for(int j = startC; j < endC; j++) {
            // global -> local
            const int r = i - rect.r, c = j - rect.c;
            
            // rotate (r, c) -> (c, L - 1 - r)
            const int newR = c, newC = rect.size - 1 - r;
            tmp[newR][newC] = max(grid[i][j] - 1, 0);

            if(i == exitR && j == exitC) {
                newExitR = newR + rect.r, newExitC = newC + rect.c;
            }
        }
    }

    // apply
    for(int i = 0; i < rect.size; i++) {
        for(int j = 0; j < rect.size; j++) {
            const int finalR = i + rect.r, finalC = j + rect.c;

            grid[finalR][finalC] = tmp[i][j];
        }
    }

    exitR = newExitR;
    exitC = newExitC;

    for(Participant& p: participants) {
        if(p.isExit) continue;

        if(startR <= p.r && p.r < endR && startC <= p.c && p.c < endC) {
            const int localR = p.r - startR, localC = p.c - startC;
            const int newR = localC, newC = rect.size - 1 - localR;
            const int finalR = newR + startR, finalC = newC + startC;

            p.move(finalR, finalC, false);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    grid.assign(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;

        participants.emplace_back(Participant(--r, --c));
    }

    cin >> exitR >> exitC;

    exitR--;
    exitC--;

    while(k--) {
        move();

        if(checkAllParticipantsExit()) {
            break;
        }

        RotateCandidate rect = getRect();
        rotate(rect);
    }

    cout << getAllMoveCount() << "\n";
    cout << ++exitR << " " << ++exitC << "\n";

    return 0;
}