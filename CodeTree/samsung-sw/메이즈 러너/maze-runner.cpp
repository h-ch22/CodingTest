#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Participant;

int n, m, k, exitR, exitC; // r: 세로, c: 가로
vector<vector<int>> grid; // 0: 빈 칸, 1~9: 벽의 내구도
vector<Participant> participants;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

struct Participant {
    int r, c, moveCount;
    bool isExit;

    Participant(int r, int c) {
        this->r = r;
        this->c = c;
        isExit = false;
        moveCount = 0;
    }

    void move(int r, int c, bool updateMoveCount) {
        if(isExit) return;

        this->r = r;
        this->c = c;

        if(updateMoveCount) {
            moveCount++;
        }

        if(r == exitR && c == exitC) {
            isExit = true;
        }
    }
};

struct RotateCandidate {
    int size, lr, lc;

    RotateCandidate(int lr, int lc, int size) {
        this->lr = lr;
        this->lc = lc;
        this->size = size;
    }

    bool operator <(const RotateCandidate& other) const {
        if(this->size == other.size) {
            if(this->lr == other.lr) {
                return this->lc < other.lc;
            }

            return this->lr < other.lr;
        }

        return this->size < other.size;
    }
};

int getDistance(const int r1, const int r2, const int c1, const int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

int getTotalDistance() {
    int total = 0;

    for(const Participant& p: participants) {
        total += p.moveCount;
    }

    return total;
}

void move() {
    for(Participant& p: participants) {
        if(p.isExit) continue;
        
        int r = p.r, c = p.c, originDistance = getDistance(r, exitR, c, exitC);

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(grid[nr][nc] == 0 && getDistance(nr, exitR, nc, exitC) < originDistance) {
                    p.move(nr, nc, true);
                    break;
                }
            }
        }
    }
}

bool isParticipantExists(const int lr, const int lc, const int size) {
    const int rr = lr + size, rc = lc + size;

    for(const Participant& p: participants) {
        if(p.isExit) continue;
        
        if(lr <= p.r && p.r < rr && lc <= p.c && p.c < rc) {
            // cout << "Participant: " << p.r << ", " << p.c << " - range: " << lr << ", " << lc << " to " << rr << ", " << rc << "\n";
            return true;
        }
    }

    return false;
}

RotateCandidate selectRect() {
    for(int size = 2; size <= n; size++) {
        for(int lr = 0; lr <= n - size; lr++) {
            for(int lc = 0; lc <= n - size; lc++) {
                int rr = lr + size - 1;
                int rc = lc + size - 1;

                if(!(lr <= exitR && exitR <= rr && lc <= exitC && exitC <= rc)) continue;

                if(isParticipantExists(lr, lc, size)) {
                    return RotateCandidate(lr, lc, size);
                }
            }
        }
    }

    return RotateCandidate(-1, -1, -1);
}

void rotate(const RotateCandidate& rect) {
    vector<vector<int>> tmp(rect.size, vector<int>(rect.size));

    for(int r = 0; r < rect.size; r++) {
        for(int c = 0; c < rect.size; c++) {
            int value = grid[rect.lr + r][rect.lc + c];

            if(value > 0) value--;
            tmp[c][rect.size - 1 - r] = value;
        }
    }

    for(int r = 0; r < rect.size; r++) {
        for(int c = 0; c < rect.size; c++) {
            grid[rect.lr + r][rect.lc + c] = tmp[r][c];
        }
    }

    int localExitR = exitR - rect.lr;
    int localExitC = exitC - rect.lc;

    exitR = rect.lr + localExitC;
    exitC = rect.lc + rect.size - 1 - localExitR;

    for(Participant& p: participants) {
        if(p.isExit) continue;

        if(rect.lr <= p.r && p.r < rect.lr + rect.size && rect.lc <= p.c && p.c < rect.lc + rect.size) {
            int localR = p.r - rect.lr;
            int localC = p.c - rect.lc;

            p.move(rect.lr + localC, rect.lc + rect.size - 1 - localR, false);
        }
    }
}

bool isAllParticipantsExit() {
    for(const Participant& p: participants) {
        if(!p.isExit) {
            return false;
        }
    }

    return true;
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
        if(isAllParticipantsExit()) {
            break;
        }

        move();
        RotateCandidate r = selectRect();

        if(r.size > -1) {
            rotate(r);
        }
    }

    cout << getTotalDistance() << "\n";
    cout << ++exitR << " " << ++exitC << "\n";

    return 0;
}

