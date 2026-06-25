#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

struct Turret;
int n, m, k, currentTurn, attacker, target, attackerPower, attackerHalfPower;
vector<vector<int>> grid;
vector<Turret> turrets;

struct Turret {
    int r, c, power, lastAttackedTurn;
    bool isAttacked;

    Turret(const int r, const int c, const int power) {
        this->r = r;
        this->c = c;
        this->power = power;
        lastAttackedTurn = 0;
        isAttacked = false;
    }

    void updatePower(const int amount, const bool updateAttackedStatus) {
        power += amount;
        grid[r][c] = power;

        if(updateAttackedStatus) isAttacked = true;
    }

    const bool operator <(const Turret& other) const {
        if(this->power != other.power) return this->power < other.power; // 1. 공격력이 낮은 순
        if(this->lastAttackedTurn != other.lastAttackedTurn) return this->lastAttackedTurn > other.lastAttackedTurn; // 2. 최근에 공격한 포탑
        if(this->r + this->c != other.r + other.c) return this->r + this->c > other.r + other.c; // 3. 행과 열의 합이 큰 포탑
        return this->c > other.c; // 열이 큰 포탑
    }
};

void selectAttacker() {
    sort(turrets.begin(), turrets.end());

    // 공격력이 낮은 순으로 정렬했지만, 공격력이 0인 경우를 선택하면 안되기 때문에 for-loop로 순회해 공격력이 0이 아닌 포탑이 나오는 순간 공격자를 선택하고 종료한다.
    for(int i = 0; i < turrets.size(); i++) {
        if(turrets[i].power > 0) {
            turrets[i].updatePower(n + m, true);

            attackerPower = turrets[i].power;
            attackerHalfPower = turrets[i].power / 2;
            attacker = i;

            // 수정 3: 최종 공격 턴 업데이트하지 않음
            turrets[i].lastAttackedTurn = currentTurn;

            return;
        }
    }
}

void selectTarget() {
    // 타겟을 선택할 때는 이미 직전에 공격자 선택 시 정렬했으므로 생략한다.
    // 역순으로 순회해 공격자의 선정 기준의 반대로 선정한다.
    for(int i = turrets.size() - 1; i >= 0; i--) {
        if(turrets[i].power > 0) {
            target = i;

            return;
        }
    }
}

int findTurret(const pair<int, int> coord) {
    for(int i = 0; i < turrets.size(); i++) {
        const Turret& t = turrets[i];

        if(t.r == coord.first && t.c == coord.second) return i;
    }

    return -1;
}

pair<int, int> getNewCoord(const pair<int, int> coord) {
    const int r = coord.first, c = coord.second;

    // 음수값이 나올 수 있기 때문에 마지막에 modulo 연산을 한번 더 함.
    return { (r % n + n) % n, (c % m + m) % m };
}

vector<vector<pair<int, int>>> bfs() {
    const pair<int, int> attackerCoord = { turrets[attacker].r, turrets[attacker].c };
    const pair<int, int> targetCoord = { turrets[target].r, turrets[target].c };

    deque<pair<int, int>> queue;
    queue.emplace_back(attackerCoord);

    // BFS에서 경로 역추적을 위해 grid와 동일한 사이즈의 배열을 만든다. 이 때 기본값인 { 0, 0 }으로 초기화하면 이 경로를 방문했는지 여부(0, 0이 이미 있기 때문)를 모르니 {-1, -1}로 초기화한다.
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m, make_pair(-1, -1)));

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        const int r = current.first, c = current.second;

        // 수정 1: attackerCoord와 비교해서 항상 빈 parents(-1)가 return됨
        if(r == targetCoord.first && c == targetCoord.second) {
            return parents;
        }

        // 우하좌상
        const int dr[4] = { 0, 1, 0, -1 };
        const int dc[4] = { 1, 0, -1, 0 };

        for(int i = 0; i < 4; i++) {
            // 이 연산은 범위 내외 상관없이 유효한 값을 반환하기 때문에 분기하지 않음.
            const pair<int, int> next = getNewCoord(make_pair(r + dr[i], c + dc[i]));
            const int nr = next.first, nc = next.second;

            // 부서지지 않은 포탑이고, 방문하지 않은 경우 방문처리 후 queue에 push
            if(parents[nr][nc].first == -1 && parents[nr][nc].second == -1 && grid[nr][nc] > 0) {
                parents[nr][nc] = current;
                queue.emplace_back(nr, nc);
            }
        }
    }

    // 탐색 실패 시 빈 vector return
    parents.clear();
    return parents;
}

// 레이저 공격 성공 여부를 알아야 다음에 포탄 공격 여부를 선택하니 bool 값을 return한다.
bool raserAttack() {
    vector<vector<pair<int, int>>> parents = bfs();

    // 탐색 실패 시 false return
    if(parents.size() == 0) return false;

    const pair<int, int> attackerCoord = { turrets[attacker].r, turrets[attacker].c };
    const pair<int, int> targetCoord = { turrets[target].r, turrets[target].c };

    const int attackerR = attackerCoord.first, attackerC = attackerCoord.second;
    const int targetR = targetCoord.first, targetC = targetCoord.second;

    // 수정 2: '역'추적이니까 target부터 부모를 찾아서 attacker까지 가야함.
    pair<int, int> current = targetCoord;

    while(true) {
        const int r = current.first, c = current.second;

        if(r == attackerR && c == attackerC) {
            turrets[target].updatePower(attackerPower * -1, true);
            return true;
        }

        current = parents[r][c];

        // 자기 자신이 아닌 경우
        // 수정 5: (어제와 같은 실수) if문에서 좌표 비교시 && 를 사용해 (current.first != attackerR && current.second != attackerC) 성립되지 않는 조건문이 됨.
        if(current.first == attackerR && current.second == attackerC) continue;
        else {
            const int idx = findTurret(current);

            if(idx > -1) {
                turrets[idx].updatePower(attackerHalfPower * -1, true);
            }
        }
    }

    return false;
}

void shellAttack() {
    const pair<int, int> attackerCoord = { turrets[attacker].r, turrets[attacker].c };
    const pair<int, int> targetCoord = { turrets[target].r, turrets[target].c };

    const int attackerR = attackerCoord.first, attackerC = attackerCoord.second;
    const int targetR = targetCoord.first, targetC = targetCoord.second;

    const int dr[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
    const int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    turrets[target].updatePower(attackerPower * -1, true);

    for(int i = 0; i < 8; i++) {
        // 수정 7: 주변 공격의 기준을 공격자로 잡아버림
        const pair<int, int> next = getNewCoord(make_pair(targetR + dr[i], targetC + dc[i]));
        const int nr = next.first, nc = next.second;

        // 수정 6: 여기도 마찬가지. 좌표 비교를 != && != 으로 해서 성립하지 않는 조건문이 됨.
        if((nr == attackerR && nc == attackerC) || (nr == targetR && nc == targetC)) continue;

        if(grid[nr][nc] > 0) {
            const int idx = findTurret(next);

            if(idx > -1) {
                turrets[idx].updatePower(attackerHalfPower * -1, true);
            }
        }
    }
}

bool checkShouldExit() {
    int count = 0;
    
    for(const Turret& t: turrets) {
        if(t.power > 0) count++;

        if(count >= 2) return false; // 부서지지 않은 포탑이 2개 이상이면 중단할 필요가 없음
    }

    return true;
}

void updatePower() {
    for(Turret& t: turrets) {
        if(t.power > 0 && !t.isAttacked) {
            t.updatePower(1, false);
        }

        t.isAttacked = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    currentTurn = 1;
    attacker = -1;
    target = -1;

    // 0으로 나누기 에러 방지
    attackerPower = 1;
    attackerHalfPower = 1;

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

    sort(turrets.begin(), turrets.end());

    while(k--) {
        // 0. 종료조건 달성 여부 확인
        if(checkShouldExit()) break;

        // 1. 공격자와 타겟 선택
        selectAttacker();
        selectTarget();

        if(attacker == -1 || target == -1) break;

        // 2. 레이저 공격 시도
        if(!raserAttack()) {
            // 3. 레이저 공격 실패 시 포탄 공격
            shellAttack();
        }

        // 4. 문제에서 종료 조건 달성 '즉시' 종료였기 때문에 공격하자마자 종료조건 달성 여부를 확인하고 종료한다.
        if(checkShouldExit()) break;

        updatePower();

        // 수정 4: currentTurn 업데이트하지 않음
        currentTurn++; 
    }

    sort(turrets.begin(), turrets.end());

    // 가장 강한 포탑 = target
    selectTarget();
    cout << turrets[target].power << "\n";

    return 0;
}