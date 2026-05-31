#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define MAX 1e6
#define MIN 0

using namespace std;

struct Turret {
    int x, y, attackTime, power;

    Turret(int x, int y, int attackTime, int power) {
        this->x = x;
        this->y = y;
        this->attackTime = attackTime;
        this->power = power;
    }

    bool operator<(const Turret& other) {
        if(power <= 0 && other.power > 0) return false;
        if(power > 0 && other.power <= 0) return true;
        if(power != other.power) return power < other.power;
        if(attackTime != other.attackTime) return attackTime > other.attackTime;
        if(x + y != other.x + other.y) return x + y > other.x + other.y;
        else return x > other.x;
    }
};

int n, m, k, currentTurn;
vector<Turret> turrets;
vector<vector<int>> attackTimes;
vector<vector<bool>> isAffected;
vector<vector<int>> grid;

int rDx[4] = { 1, 0, -1, 0 };
int rDy[4] = { 0, 1, 0, -1 };

int sDx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int sDy[8] = { 0, -1, 0, 1, -1, 1, -1, 1 };

int getMaxPowerTurret() {
    for(int i = turrets.size() - 1; i >= 0; i--) {
        if(turrets[i].power > 0) {
            return i;
        }
    }
}

vector<Turret> select() {
    sort(turrets.begin(), turrets.end());

    int idx = getMaxPowerTurret();
    Turret target = turrets[idx];

    turrets[0].power += (n + m);
    turrets[0].attackTime = currentTurn;

    grid[turrets[0].y][turrets[0].x] += (n + m);

    Turret attacker = turrets[0];

    // for(const Turret& t: turrets) {
    //     cout << t.y << "," << t.x << " : " << t.power << "\n";
    // }

    isAffected[target.y][target.x] = true;
    attackTimes[attacker.y][attacker.x] = currentTurn;

    return vector<Turret>{ attacker, target };
}

/*
* bool raserAttack(attacker: pair<int, int>, target: pair<int, int>)
* attacker가 target에게 레이저 공격을 한다.
* return 값이 false인 경우 attacker가 target에게 갈 수 있는 경로가 없는 상태를 의미한다.
*/
bool raserAttack(const Turret attacker, const Turret target) {
    deque<pair<int, int>> queue;

    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m));

    queue.emplace_back(attacker.y, attacker.x);
    visited[attacker.y][attacker.x] = true;

    while(!queue.empty()) {
        pair<int, int> current = queue.front();
        queue.pop_front();

        if(current == make_pair(target.y, target.x)) {
            // cout << grid[target.y][target.x] << " -> ";
            grid[target.y][target.x] -= attacker.power;
            // cout << grid[target.y][target.x] << "\n";

            pair<int, int> trace = parents[current.first][current.second];

            while(trace != make_pair(attacker.y, attacker.x)) {
                // cout << "Trace: " << grid[trace.first][trace.second] << " -> ";
                grid[trace.first][trace.second] -= (attacker.power / 2);
                // cout << grid[trace.first][trace.second] << " : ";

                isAffected[trace.first][trace.second] = true;

                // cout << "(" << trace.first << ", " << trace.second << ")" << "\n";
                trace = parents[trace.first][trace.second];
            }

            return true;
        }

        for(int i = 0; i < 4; i++) {
            int ny = current.first + rDy[i];
            int nx = current.second + rDx[i];

            ny = (ny % n + n) % n;
            nx = (nx % m + m) % m;

            if(grid[ny][nx] > 0 && !visited[ny][nx]) {
                queue.emplace_back(ny, nx);
                parents[ny][nx] = current;
                visited[ny][nx] = true;
            }
        }
    }

    return false;
}

void shellAttack(const Turret attacker, const Turret target) {
    grid[target.y][target.x] -= attacker.power;

    for(int i = 0; i < 8; i++) {
        int ny = target.y + sDy[i];
        int nx = target.x + sDx[i];

        ny = (ny % n + n) % n;
        nx = (nx % m + m) % m;

        if(ny == attacker.y && nx == attacker.x) continue;

        grid[ny][nx] -= (attacker.power / 2);
        isAffected[ny][nx] = true;
    }
}

void syncPower() {
    for(Turret& t: turrets) {
        t.power = grid[t.y][t.x];
    }
}

void increasePower() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(attackTimes[i][j] != currentTurn && !isAffected[i][j] && grid[i][j] > 0) {
                grid[i][j] += 1;
            }
        }
    }
}

bool shouldStop() {
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] > 0) {
                count++;

                if(count > 1) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    currentTurn = 1;

    cin >> n >> m >> k;
    grid.assign(n, vector<int>(m));
    attackTimes.assign(n, vector<int>(m));
    isAffected.assign(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int power;
            cin >> power;

            turrets.emplace_back(Turret(j, i, 0, power));
            grid[i][j] = power;
        }
    }

    while(k--) {
        vector<Turret> selected = select();
        Turret attacker = selected[0], target = selected[1];

        // cout << "Attacker: " << attacker.y << ", " << attacker.x << " (Power: " << attacker.power << ") " << "Target: " << target.y << ", " << target.x << " (Power: " << target.power << ")" << "\n";

        bool raserAttackResult = raserAttack(attacker, target);

        if(!raserAttackResult) {
            shellAttack(attacker, target);
        }

        if(shouldStop()) {
            break;
        }

        increasePower();
        syncPower();
        isAffected.assign(n, vector<bool>(m, false));
        currentTurn++;

        // for(const Turret& t: turrets) {
        //    cout << t.y << ", " << t.x << ": " << t.power << "\n";
        // }
    }

    sort(turrets.begin(), turrets.end());

    int maxIdx = getMaxPowerTurret();

    cout << turrets[maxIdx].power << "\n";

    return 0;
}
