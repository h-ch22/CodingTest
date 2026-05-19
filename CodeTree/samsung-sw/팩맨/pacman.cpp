#include <iostream>
#include <vector>
#include <algorithm>

#define GRID_SIZE 4

using namespace std;

struct Monster;
int m, t, r, c, currentTurn, nextId; // r: 세로, c: 가로
int grid[GRID_SIZE][GRID_SIZE][8] = { 0, };
int corpse[GRID_SIZE][GRID_SIZE] = { 0, };
int willBorn[GRID_SIZE][GRID_SIZE][8] = { 0, };

int mDr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int mDc[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int pDr[4] = { -1, 0, 1, 0 };
int pDc[4] = { 0, -1, 0, 1 };

void duplicateMonsters() {
    for(int i = 0; i < GRID_SIZE; i++) {
      for(int j = 0; j < GRID_SIZE; j++) {
        for(int k = 0; k < 8; k++) {
          willBorn[i][j][k] = grid[i][j][k];
        }
      }
    }
}

bool validateCoords(const int r, const int c) {
    return 0 <= r && r < GRID_SIZE && 0 <= c && c < GRID_SIZE;
}

bool isCorpseExists(const int r, const int c) {
    return corpse[r][c] > 0;
}

int getDirection(const int direction, const int r, const int c) {
    for(int i = direction + 1; i < 8; i++) {
        int nr = r + mDr[i], nc = c + mDc[i];

        if(nr == ::r && nc == ::c) {
            continue;
        }

        if(validateCoords(nr, nc) && !isCorpseExists(nr, nc)) {
            return i;
        }
    }

    for(int i = 0; i < direction; i++) {
        int nr = r + mDr[i], nc = c + mDc[i];

        if(nr == ::r && nc == ::c) {
            continue;
        }

        if(validateCoords(nr, nc) && !isCorpseExists(nr, nc)) {
            return i;
        }
    }

    return direction;
}

int getMonsterCount(int r, int c) {
    int count = 0;

    for(int i = 0; i < 8; i++) {
        count += grid[r][c][i];
    }

    return count;
}

void moveMonsters() {
    int nextGrid[GRID_SIZE][GRID_SIZE][8] = { 0, };

    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            for(int k = 0; k < 8; k++) {
                if(grid[i][j][k] > 0) {
                    int nr = i + mDr[k], nc = j + mDc[k], nd = k;

                    if(!validateCoords(nr, nc) || isCorpseExists(nr, nc) || (r == nr && c == nc)) {
                        int newDir = getDirection(k, i, j);

                        if(newDir == k) {
                            nr = i, nc = j;
                        } else {
                            nr = i + mDr[newDir], nc = j + mDc[newDir];
                            nd = newDir;
                        }
                    }

                    nextGrid[nr][nc][nd] += grid[i][j][k];
                }
            }
        }
    }

    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            for(int k = 0; k < 8; k++) {
                grid[i][j][k] = nextGrid[i][j][k];
            }
        }
    }
}

void movePacman() {
    vector<pair<int, int>> moves(3);

    int maxCount = -1;
    
    for(int i = 0; i < 4; i++) {
        int nRi = r + pDr[i];
        int nCi = c + pDc[i];

        if(validateCoords(nRi, nCi)) {
            for(int j = 0; j < 4; j++) {
                int nRj = nRi + pDr[j];
                int nCj = nCi + pDc[j];

                if(validateCoords(nRj, nCj)) {
                    for(int k = 0; k < 4; k++) {
                        int nRk = nRj + pDr[k];
                        int nCk = nCj + pDc[k];

                        if(validateCoords(nRk, nCk)) {
                            int iCount = getMonsterCount(nRi, nCi);
                            int jCount = getMonsterCount(nRj, nCj);
                            int kCount = getMonsterCount(nRk, nCk);

                            if(nRi == nRj && nCi == nCj) {
                                jCount -= iCount;
                            }

                            if(nRj == nRk && nCj == nCk) {
                                kCount -= jCount;
                            }

                            if(nRi == nRk && nCi == nCk) {
                                kCount -= iCount;
                            }

                            const int count = iCount + jCount + kCount;

                            if(count > maxCount) {
                                maxCount = count;
                                moves[0] = { nRi, nCi };
                                moves[1] = { nRj, nCj };
                                moves[2] = { nRk, nCk };
                            }
                        }
                    }
                }
            }
        }
    }

    for(const pair<int, int> p: moves) {
        r = p.first, c = p.second;

        for(int i = 0; i < 8; i++) {
            if(grid[r][c][i] > 0) {
                corpse[r][c] = currentTurn + 2;
            }
            
            grid[r][c][i] = 0;
        }
    }
}

void deleteCorpse() {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(corpse[i][j] == currentTurn) {
                corpse[i][j] = 0;
            }
        }
    }
}

void bornMonsters() {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            for(int k = 0; k < 8; k++) {
                grid[i][j][k] += willBorn[i][j][k];
                willBorn[i][j][k] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> t >> r >> c;
    
    r--;
    c--;
    currentTurn = 1;
    nextId = m;

    for(int i = 0; i < m; i++) {
        int r, c, d;
        cin >> r >> c >> d;

        grid[r - 1][c - 1][d - 1]++;
    }

    while(currentTurn <= t) {
        duplicateMonsters();
        moveMonsters();
        movePacman();
        deleteCorpse();
        bornMonsters();
        currentTurn++;
    }

    int count = 0;

    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            count += getMonsterCount(i, j);
        }
    }

    cout << count << "\n";

    return 0;
}
