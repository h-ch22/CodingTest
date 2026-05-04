#include <bits/stdc++.h>

using namespace std;

// 좌 우 상 하 좌하 우상 좌상 우하
int dr[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dc[8] = { 0, 0, -1, 1, 1, -1, -1, 1 };

struct Santa {
    /*
    * r: 가로
    * c: 세로
    */
    int id, r, c, dr, dc, passOutDuration, point;
    bool isPassOut, isFailed;

    Santa() {
        id = -1;
        r = -1;
        c = -1;
        dr = -1;
        dc = -1;
        passOutDuration = -1;
        point = 0;
        isPassOut = false;
        isFailed = false;
    }

    void setPassOut(int passOutDuration) {
        this->passOutDuration = passOutDuration;
        isPassOut = true;
    }

    void wakeUp() {
        isPassOut = false;
        passOutDuration = -1;
    }

    void setFailed() {
        isFailed = true;
        r = -1;
        c = -1;
        isPassOut = false;
        passOutDuration = -1;
    }

    void addPoint(int p) {
        point += p;
    }

    void move(int r, int c) {
        this->r = r;
        this->c = c;
    }
};

int getDistance(int r1, int c1, int r2, int c2) {
    return ((r1 - r2) * (r1 - r2)) + ((c1 - c2) * (c1 - c2));
}

void checkAllFailed(const vector<Santa>& santas) {
    for(const Santa& santa: santas) {
        if(!santa.isFailed) {
            return;
        }
    }

    for(const Santa& santa: santas) {
        cout << santa.point << " ";
    }

    cout << "\n";
    exit(0);
}

int getSantaIdx(const vector<Santa>& santas, const int id) {
    auto it = find_if(santas.begin(), santas.end(), [id](const Santa& s) {
        return s.id == id;
    });

    if(it != santas.end()) {
        return distance(santas.begin(), it);
    } else {
        return -1;
    }
}

void pushOutSanta(vector<Santa>& santas, vector<vector<int>>& grid, int target, int dir_r, int dir_c, int force) {
    int toR = santas[target].r + (dir_r * force);
    int toC = santas[target].c + (dir_c * force);

    if (grid[santas[target].r][santas[target].c] == santas[target].id) {
        grid[santas[target].r][santas[target].c] = -1;
    }

    if(1 <= toR && toR < grid.size() && 1 <= toC && toC < grid.size()) {
        if(grid[toR][toC] > 0) {
            int victimIdx = getSantaIdx(santas, grid[toR][toC]);
            pushOutSanta(santas, grid, victimIdx, dir_r, dir_c, 1);
        }
        
        grid[toR][toC] = santas[target].id;
        santas[target].move(toR, toC);
    } else {
        santas[target].setFailed(); 
    }
}

void moveRudolph(int& r_r, int& r_c, const int c, const int m, vector<Santa>& santas, vector<vector<int>>& grid) {
    vector<Santa> shortest;

    for(const Santa& s: santas) {
        if(s.isFailed) continue;

        int distance = getDistance(r_r, r_c, s.r, s.c);

        if(shortest.empty()) {
            shortest.emplace_back(s);
        } else {
            int distanceToShortest = getDistance(r_r, r_c, shortest[0].r, shortest[0].c);

            if(distanceToShortest == distance) {
                shortest.emplace_back(s);
                sort(shortest.begin(), shortest.end(), [](const Santa& a, const Santa& b){
                    if(a.r == b.r) return a.c > b.c;
                    return a.r > b.r;
                });
            } else if(distanceToShortest > distance) {
                shortest.clear();
                shortest.emplace_back(s);
            }
        }
    }

    int toR = -1, toC = -1, shortestDistance = 1000000, direction = -1;

    for(int i = 0; i < 8; i++) {
        int nR = r_r + dr[i];
        int nC = r_c + dc[i];

        if(1 <= nR && nR < grid.size() && 1 <= nC && nC < grid.size()) {
            int distance = getDistance(shortest[0].r, shortest[0].c, nR, nC);

            if(distance < shortestDistance) {
                shortestDistance = distance;
                toR = nR;
                toC = nC;
                direction = i;
            }
        }
    }

    if(grid[toR][toC] > 0) {
        // 충돌
        int target = getSantaIdx(santas, grid[toR][toC]);

        if(target > -1) {
            santas[target].addPoint(c);
            pushOutSanta(santas, grid, target, dr[direction], dc[direction], c);
            grid[toR][toC] = 0;
            santas[target].setPassOut(m - 1);
        }
    }

    grid[r_r][r_c] = -1;
    r_r = toR;
    r_c = toC;
    grid[r_r][r_c] = 0;
}

void moveSanta(vector<Santa>& santas, vector<vector<int>>& grid, const int d, const int r_r, const int r_c, const int m) {
    int drR[4] = { -1, 0, 1, 0 };
    int drC[4] = { 0, 1, 0, -1 };
    
    for(int i = 0; i < santas.size(); i++) {
        if(santas[i].isPassOut || santas[i].isFailed) continue;

        int shortest = 9999, dirR = -2, dirC = -2;
        int toRudolphDistance = getDistance(r_r, r_c, santas[i].r, santas[i].c);
        shortest = toRudolphDistance;

        for(int j = 0; j < 4; j++) {
            int nr = santas[i].r + drR[j], nc = santas[i].c + drC[j];

            if(1 <= nr && nr < grid.size() && 1 <= nc && nc < grid.size()) {
                if(grid[nr][nc] > 0) continue;

                int distance = getDistance(r_r, r_c, nr, nc);

                if(distance < shortest) {
                    shortest = distance;
                    dirR = drR[j];
                    dirC = drC[j];
                }
            }
        }

        if(dirR != -2 && dirC != -2) {
            int nr = santas[i].r + dirR, nc = santas[i].c + dirC;

            if(grid[nr][nc] == 0) {
                santas[i].addPoint(d);
                grid[santas[i].r][santas[i].c] = -1;
                santas[i].move(nr, nc);
                pushOutSanta(santas, grid, i, dirR * -1, dirC * -1, d);
                santas[i].setPassOut(m - 1);
            } else {
                grid[santas[i].r][santas[i].c] = -1;
                grid[nr][nc] = santas[i].id;
                santas[i].move(nr, nc);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
    * n: 게임판의 크기
    * m: 게임 턴 수
    * p: 산타의 수
    * c: 루돌프의 힘
    * d: 산타의 힘
    */
    int n, m, p, c, d, r_r, r_c;
    cin >> n >> m >> p >> c >> d >> r_r >> r_c;

    /*
    * -1: 비어있음
    * 0: 루돌프
    * 1~: 산타
    */
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, -1));
    vector<Santa> santas(p);

    for(int i = 0; i < p; i++) {
        int id, s_r, s_c;
        cin >> id >> s_r >> s_c;

        santas[i].id = id;
        santas[i].r = s_r;
        santas[i].c = s_c;
        grid[s_r][s_c] = id;
    }

    grid[r_r][r_c] = 0;

    sort(santas.begin(), santas.end(), [](const Santa& a, const Santa& b) {
        return a.id < b.id;
    });

    while(m--) {
        for(Santa& s: santas) {
            if(s.isPassOut && s.passOutDuration > m) {
                s.wakeUp();
            }
        }

        // 루돌프의 움직임
        moveRudolph(r_r, r_c, c, m, santas, grid);
        checkAllFailed(santas);

        // 산타의 움직임
        moveSanta(santas, grid, d, r_r, r_c, m);
        checkAllFailed(santas);

        for(Santa& s: santas) {
            if(!s.isFailed) {
                s.addPoint(1);
            }
        }
    }

    for(const Santa& s: santas) {
        cout << s.point << " ";
    }

    cout << "\n";

    return 0;
}
