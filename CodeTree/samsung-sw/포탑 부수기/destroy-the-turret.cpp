#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

struct Turret;

int n, m, k, currentTurn, attacker, target;
vector<vector<int>> grid;
vector<Turret> turrets;

struct Turret {
    int lastAttackedTurn, power, r, c;
    bool isAttacked;

    Turret(int r, int c, int power) {
        this->r = r;
        this->c = c;
        this->power = power;
        
        lastAttackedTurn = 0;
        isAttacked = false;
    }

    void changePower(const int newPower) {
        if(newPower < power) isAttacked = true;
        grid[r][c] = newPower;
        power = newPower;
    }

    void updateAttackedStatus() {
        isAttacked = false;
    }

    const bool operator <(const Turret& other) const {
        if(power != other.power) return power < other.power;
        if(lastAttackedTurn != other.lastAttackedTurn) return lastAttackedTurn > other.lastAttackedTurn;
        if(r + c != other.r + other.c) return r + c > other.r + other.c;

        return c > other.c;
    }
};

void selectAttacker() {
    sort(turrets.begin(), turrets.end());

    for(int i = 0; i < turrets.size(); i++) {
        if(turrets[i].power > 0) {
            attacker = i;
            turrets[i].changePower(turrets[i].power + (n + m));
            turrets[i].lastAttackedTurn = currentTurn;
            return;
        }
    }
}

void selectTarget() {
    for(int i = turrets.size() - 1; i >= 0; i--) {
        if(turrets[i].power > 0) {
            target = i;
            return;
        }
    }
}

int getTurret(int r, int c) {
    for(int i = 0; i < turrets.size(); i++) {
        if(turrets[i].r == r && turrets[i].c == c) {
            return i;
        }
    }
}

bool raserAttack() {
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m, make_pair(-1, -1)));
    vector<pair<int, int>> targets;
    deque<pair<int, int>> queue;

    const int dr[4] = { 0, 1, 0, -1 };
    const int dc[4] = { 1, 0, -1, 0 };

    queue.emplace_back(turrets[attacker].r, turrets[attacker].c);

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        const int r = current.first, c = current.second;

        const Turret targetTurret = turrets[target];

        if(targetTurret.r == current.first && targetTurret.c == current.second) {
            const int p = turrets[attacker].power;
            turrets[target].changePower(turrets[target].power - p);

            int currentR = r, currentC = c;

            while(true) {
                const pair<int, int> to = parents[currentR][currentC];
                currentR = to.first, currentC = to.second;

                if(currentR == turrets[attacker].r && currentC == turrets[attacker].c) {
                    break;
                }

                targets.emplace_back(currentR, currentC);
            }

            for(const pair<int, int> t: targets) {
                const int idx = getTurret(t.first, t.second);
                turrets[idx].changePower(turrets[idx].power - (p / 2));
            }

            return true;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 다시 한번 물어보기: 공식
            nr = (nr % n + n) % n;
            nc = (nc % m + m) % m;

            if(parents[nr][nc].first == -1 && parents[nr][nc].second == -1 && grid[nr][nc] > 0) {
                parents[nr][nc] = current;
                queue.emplace_back(nr, nc);
            }
        }
    }

    return false;
}

void shellAttack() {
    const int dr[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
    const int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    const int tR = turrets[target].r, tC = turrets[target].c;
    const int aP = turrets[attacker].power;

    turrets[target].changePower(turrets[target].power - aP);

    for(int i = 0; i < 8; i++) {
        int nr = tR + dr[i];
        int nc = tC + dc[i];

        nr = (nr % n + n) % n;
        nc = (nc % m + m) % m;

        if(grid[nr][nc] <= 0) continue;

        const int idx = getTurret(nr, nc);
        
        if(turrets[idx].power > 0 && idx != attacker) {
            turrets[idx].changePower(turrets[idx].power - (aP / 2));
        }
    }
}

void updatePower() {
    for(int i = 0; i < turrets.size(); i++) {
        if(i != attacker && i != target && turrets[i].power > 0 && !turrets[i].isAttacked) {
            turrets[i].changePower(turrets[i].power + 1);
        }
    }
}

bool shouldStop() {
    int count = 0;

    for(const Turret& t: turrets) {
        if(t.power > 0) count++;

        if(count > 1) return false;
    }

    return true;
}

void resetAttackStatus() {
    for(Turret& t: turrets) {
        t.updateAttackedStatus();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    grid.assign(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int power;
            cin >> power;

            grid[i][j] = power;

            if(power > 0) {
                turrets.emplace_back(Turret(i, j, power));
            }
        }
    }

    currentTurn = 1;

    while(k--) {
        resetAttackStatus();

        if(shouldStop()) break;

        selectAttacker();
        selectTarget();
        
        if(!raserAttack()) {
            shellAttack();
        }

        if(shouldStop()) break;

        updatePower();
        
        currentTurn++;
    }

    sort(turrets.begin(), turrets.end());

    for(int i = turrets.size() - 1; i >= 0; i--) {
        if(turrets[i].power > 0) {
            cout << turrets[i].power << "\n";
            break;
        }
    }

    return 0;
}