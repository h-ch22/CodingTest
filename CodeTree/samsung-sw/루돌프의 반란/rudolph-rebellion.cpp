#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, p, c, d, r_r, r_c, currentTurn;

struct Santa {
    int id, r, c, score, passOutTurn;
    bool isOut, isPassOut;

    Santa(): id(-1), r(-1), c(-1), score(0), passOutTurn(-1), isOut(false), isPassOut(false) {}
    Santa(int id, int r, int c) {
        this->id = id;
        this->r = r;
        this->c = c;
        score = 0;
        isOut = false;
        isPassOut = false;
        passOutTurn = -1;
    }

    void setPassout() {
        isPassOut = true;
        passOutTurn = currentTurn + 2;
    }

    void wakeUp() {
        if(!isOut && currentTurn == passOutTurn) {
            isPassOut = false;
            passOutTurn = -1;
        }
    }

    void setDie() {
        r = -1;
        c = -1;
        isOut = true;
    }
};

vector<Santa> santas;

int dRR[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dRC[8] = { 0, 0, -1, 1, 1, -1, -1, 1 };

// 상-우-하-좌
int dSR[4] = { -1, 0, 1, 0 };
int dSC[4] = { 0, 1, 0, -1 };

int getDistance(int r1, int r2, int c1, int c2) {
    return abs(((r1 - r2) * (r1 - r2)) + ((c1 - c2) * (c1 - c2)));
}

pair<int, int> getShortestSanta() {
    vector<Santa> shortestSantas;
    int shortest = 2 * (n * n);

    for(const Santa& s: santas) {
        if(!s.isOut) {
            int distance = getDistance(r_r, s.r, r_c, s.c);

            if(distance < shortest) {
                shortestSantas.clear();
                shortest = distance;

                shortestSantas.emplace_back(s);
            } else if(distance == shortest) {
                shortestSantas.emplace_back(s);
            }
        }
    }

    sort(shortestSantas.begin(), shortestSantas.end(), [](const Santa& s1, const Santa& s2){
        if(s1.r == s2.r) {
            return s1.c > s2.c;
        }

        return s1.r > s2.r;
    });

    return { shortestSantas[0].r, shortestSantas[0].c };
}

bool isSantaExists(const int r, const int c) {
    for(const Santa& s: santas) {
        if(s.r == r && s.c == c) {
            return true;
        }
    }

    return false;
}

void pushOutSanta(int id, int r, int c, int dr, int dc) {
    for(Santa& s: santas) {
        if(s.id == id) {
            continue;
        }

        if(s.r == r && s.c == c) {
            // cout << "PushOut: " << s.id << " | " << s.r << ", " << s.c << " -> " << s.r - dr << ", " << s.c - dc << "( " << dr << ", " << dc << ")" << "\n";
            s.r += dr;
            s.c += dc; 

            if(s.r < 0 || s.r >= n || s.c < 0 || s.c >= n) {
                s.setDie();
                continue;
            }

            pushOutSanta(s.id, s.r, s.c, dr, dc);
        }
    }
}

void handleCollision(const pair<int, int> distance, const bool isSantaMoved) {
    int toR = distance.first * (isSantaMoved ? d : c);
    int toC = distance.second * (isSantaMoved ? d : c);

    if(isSantaMoved) {
        toR *= -1;
        toC *= -1;
    }

    const int pushR = isSantaMoved ? distance.first * -1 : distance.first;
    const int pushC = isSantaMoved ? distance.second * -1 : distance.second;
    
    for(Santa& s: santas) {
        if(s.r == r_r && s.c == r_c) {
            if(isSantaMoved) {
                // cout << "Santa " << s.id << " get points: " << s.score << " + " << d << ": " << s.score + d << "\n";

                s.score += d;
            } else {
                // cout << "Santa " << s.id << " get points: " << s.score << " + " << c << ": " << s.score + c << "\n";

                s.score += c;
            }

            const int expectedR = s.r + toR, expectedC = s.c + toC;

            // cout << "Collision: " << s.id << " | " << s.r << ", " << s.c << " -> " << expectedR << ", " << expectedC << "\n";

            if(expectedR < 0 || expectedR >= n || expectedC < 0 || expectedC >= n) {
                // cout << "Die: " << s.id << "\n";
                s.setDie();
                continue;
            }

            s.r = expectedR;
            s.c = expectedC;

            pushOutSanta(s.id, s.r, s.c, pushR, pushC);
            s.setPassout();
        }
    }
}

void moveRudolph() {
    pair<int, int> to = getShortestSanta();
    int shortest = 2 * (n * n);

    int dr = 0, dc = 0;

    for(int i = 0; i < 8; i++) {
        int nr = r_r + dRR[i];
        int nc = r_c + dRC[i];

        if(0 <= nr && nr < n && 0 <= nc && nc < n) {
            int distance = getDistance(to.first, nr, to.second, nc);

            if(distance < shortest) {
                shortest = distance;
                dr = dRR[i];
                dc = dRC[i];
            }
        }
    }

    // cout << "Move Rudolph: " << r_r << ", " << r_c << " -> " << r_r + dr << ", " << r_c + dc << "\n";
    r_r += dr;
    r_c += dc;

    handleCollision({ dr, dc }, false);
}

void moveSantas() {
    for(Santa& s: santas) {
        int shortest = 2 * (n * n);
        int toR = s.r, toC = s.c;
        int dr = 0, dc = 0;
        int originalDistance = getDistance(s.r, r_r, s.c, r_c);

        if(!s.isPassOut && !s.isOut) {
            for(int i = 0; i < 4; i++) {
                int nr = s.r + dSR[i];
                int nc = s.c + dSC[i];

                if(0 <= nr && nr < n && 0 <= nc && nc < n && !isSantaExists(nr, nc)) {
                    int distance = getDistance(nr, r_r, nc, r_c);

                    if(distance < shortest && distance < originalDistance) {
                        shortest = distance;
                        toR = nr;
                        toC = nc;
                        dr = dSR[i];
                        dc = dSC[i];
                    }
                }
            }

            if(s.r == toR && s.c == toC) {
                continue;
            }

            s.r = toR;
            s.c = toC;
            // cout << "Move Santa: " << s.id << " | " << s.r << ", " << s.c << " (" << dr << ", " << dc << ")" << "\n";
            handleCollision({ dr, dc }, true);
        }
    }
}

void wakeUp() {
    for(Santa& s: santas) {
        s.wakeUp();
    }
}

void givePoints() {
    for(Santa& s: santas) {
        if(!s.isOut) {
            s.score++;
        }
    }
}

bool isAllSantaOut() {
    for(Santa& s: santas) {
        if(!s.isOut) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> p >> c >> d >> r_r >> r_c;
    r_r--;
    r_c--;
    currentTurn = 1;

    for(int i = 0; i < p; i++) {
        int id, s_r, s_c;
        cin >> id >> s_r >> s_c;

        santas.emplace_back(Santa(id, s_r - 1, s_c - 1));
    }

    sort(santas.begin(), santas.end(), [](const Santa& a, const Santa& b){
        return a.id < b.id;
    });

    while(m--) {
        if(currentTurn > 1) {
            if(isAllSantaOut()) {
                break;
            }

            wakeUp();
        }

        // 루돌프를 움직인다.
        moveRudolph();

        // 산타를 움직인다.
        moveSantas();

        currentTurn++;

        givePoints();
    }

    for(const Santa& s: santas) {
        cout << s.score << " ";
    }

    cout << "\n";

    return 0;
}
