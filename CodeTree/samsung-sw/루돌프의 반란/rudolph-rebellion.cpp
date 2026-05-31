#include <iostream>
#include <vector>
#include <algorithm>

#define MIN 1e6

using namespace std;

struct Santa;

int n, m, p, c, d, rR, rC, currentTurn; // n: 게임 판의 크기, m: 턴 수, p: 산타의 수, c: 루돌프의 힘, d: 산타의 힘, r: 세로, c: 가로
vector<Santa> santas;
vector<vector<int>> grid; // -1: 루돌프, 0: 빈 칸, 1~ : 산타 id

struct Santa {
    int id, r, c, score, passOutTurn;
    bool isOut, isPassOut;

    Santa(): id(-1), r(-1), c(-1), score(0), passOutTurn(-1), isOut(false), isPassOut(false) {}

    Santa(int id, int r, int c) {
        this->id = id;
        this->r = r;
        this->c = c;
        this->score = 0;
        this->passOutTurn = -1;
        this->isOut = false;
        this->isPassOut = false;
    }

    void move(const int nr, const int nc) {
        // cout << "Move " << id << " from " << r << ", " << c << " to " << nr << ", " << nc << "\n";

        grid[r][c] = 0;
        
        if(nr < 0 || n <= nr || nc < 0 || n <= nc) {
            // cout << id << " is Out!\n";
            isOut = true;
            return;
        }

        r = nr;
        c = nc;
        grid[r][c] = id;
    }

    void setPassOut() {
        // cout << id << " is Passout!\n";
        isPassOut = true;
        passOutTurn = currentTurn + 2;
    }

    void wakeUp() {
        if(isPassOut && !isOut && currentTurn == passOutTurn) {
            isPassOut = false;
            passOutTurn = -1;
        }
    }

    void increaseScore(const int amount) {
        if(isOut) return;
        score += amount;
    }

    bool operator <(const Santa& other) const {
        return this->id < other.id;
    }
};

int rDr[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int rDc[8] = { 0, 0, -1, 1, 1, -1, -1, 1 };

int sDr[4] = { -1, 0, 1, 0 };
int sDc[4] = { 0, 1, 0, -1 };

int getDistance(int r1, int r2, int c1, int c2) {
    return ((r1 - r2) * (r1 - r2)) + ((c1 - c2) * (c1 - c2));
}

Santa getShortestSanta() {
    vector<Santa> shortest;
    int shortestDist = MIN;

    for(const Santa& s: santas) {
        if(s.isOut) continue;
        int distance = getDistance(rR, s.r, rC, s.c);
        
        if(distance < shortestDist) {
            shortestDist = distance;
            shortest.clear();
            shortest.emplace_back(s);
        } else if(distance == shortestDist) {
            shortest.emplace_back(s);
        }
    }

    sort(shortest.begin(), shortest.end(), [](const Santa& s1, const Santa& s2){
        if(s1.r == s2.r) {
            return s1.c > s2.c;
        }

        return s1.r > s2.r;
    });

    return shortest[0];
}

int getSantaIdx(const int id) {
    auto i = find_if(santas.begin(), santas.end(), [id](const Santa& s){
        return id == s.id;
    });

    return distance(santas.begin(), i);
}

void handleInteraction(const int r, const int c, const int dR, const int dC) {
    const int id = grid[r][c];
    const int idx = getSantaIdx(id);
    const int nr = r + dR;
    const int nc = c + dC;

    // cout << r << ", " << c << " : " << dR << " - " << dC << "\n";
    
    if(0 <= nr && nr < n && 0 <= nc && nc < n) {
        if(grid[nr][nc] >= 1 && grid[nr][nc] != id) {
            handleInteraction(nr, nc, dR, dC);
        }
    }

    santas[idx].move(nr, nc);
}

void handleCollision(const int id, const int r, const int c, const int dR, const int dC, const bool isFromRudolph) {
    const int idx = getSantaIdx(id);
    santas[idx].setPassOut();

    int nDr = dR, nDc = dC;
    int nr = r, nc = c;

    if(isFromRudolph) {
        santas[idx].increaseScore(::c);
        nDr = dR * ::c;
        nDc = dC * ::c;
    } else {
        santas[idx].increaseScore(d);
        nDr = dR * -1 * d;
        nDc = dC * -1 * d;
    }

    nr += nDr;
    nc += nDc;
    
    // cout << nr << ", " << nc << " : " << nDr << ", " << nDc << "(" << idx << "-" << id << ")" << "\n";
    
    if(0 <= nr && nr < n && 0 <= nc && nc < n) {
        if(grid[nr][nc] >= 1 && grid[nr][nc] != id) {
            handleInteraction(nr, nc, isFromRudolph ? dR : dR * -1, isFromRudolph ? dC : dC * -1);
        }
    }
    
    santas[idx].move(nr, nc);
}

void moveRudolph() {
    const Santa& shortest = getShortestSanta();
    int dist = MIN;
    int toR = rR, toC = rC, dR = 0, dC = 0;

    for(int i = 0; i < 8; i++) {
        const int nR = rR + rDr[i];
        const int nC = rC + rDc[i];

        if(0 <= nR && nR < n && 0 <= nC && nC < n) {
            int d = getDistance(shortest.r, nR, shortest.c, nC);

            if(d < dist) {
                dist = d;
                toR = nR;
                toC = nC;
                dR = rDr[i];
                dC = rDc[i];
            }
        }
    }
    
    if(grid[toR][toC] >= 1) {
        // cout << "Collision!\n";
        handleCollision(grid[toR][toC], toR, toC, dR, dC, true);
    }

    swap(grid[rR][rC], grid[toR][toC]);

    // cout << "Move rudolph from " << rR << ", " << rC << " to " << toR << ", " << toC << "\n";
    rR = toR, rC = toC;
}

void moveSanta() {
    for(Santa& s: santas) {
        if(s.isOut || s.isPassOut) continue;

        int r = s.r, c = s.c, minDist = MIN, toR = s.r, toC = s.c, dR = 0, dC = 0, currentDist = getDistance(s.r, rR, s.c, rC);

        for(int i = 0; i < 4; i++) {
            int nr = r + sDr[i], nc = c + sDc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n && grid[nr][nc] <= 0) {
                int dist = getDistance(nr, rR, nc, rC);
                
                if(dist >= currentDist) continue;
                
                if(dist < minDist) {
                    minDist = dist;
                    toR = nr;
                    toC = nc;
                    dR = sDr[i];
                    dC = sDc[i];
                }
            }
        }
        
        // cout << s.id << " : " << s.r << ", " << s.c << " -> " << toR << ", " << toC << "\n";

        if(grid[toR][toC] == -1) {
            handleCollision(s.id, toR, toC, dR, dC, false);
        } else {
            s.move(toR, toC);
        }
    }
}

bool isAllOut() {
    for(const Santa& s: santas) {
        if(!s.isOut) return false;
    }
    
    return true;
}

void wakeUp() {
    for(Santa& s: santas) {
        s.wakeUp();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> p >> c >> d >> rR >> rC;

    rR--;
    rC--;
    currentTurn = 1;

    grid.assign(n, vector<int>(n));
    santas.assign(p, Santa());

    for(int i = 0; i < p; i++) {
        int id, sR, sC;
        cin >> id >> sR >> sC;

        santas[i] = Santa(id, --sR, --sC);
        grid[sR][sC] = id;
    }

    sort(santas.begin(), santas.end());
    grid[rR][rC] = -1;
    
    for(const Santa& s: santas) {
        // cout << s.id << " : " << s.r << ", " << s.c << "\n";
    }

    while(m--) {
        if(isAllOut()) {
            break;
        }
        
        // cout << "===== Turn " << currentTurn << " =====\n";

        wakeUp();
        moveRudolph();
        moveSanta();

        for(Santa& s: santas) {
            s.increaseScore(1);
        }

        currentTurn++;
    }

    for(const Santa& s: santas) {
        cout << s.score << " ";
    }

    cout << "\n";

    return 0;
}