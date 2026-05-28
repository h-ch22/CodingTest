#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51

using namespace std;

int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Atom {
    // x: 행, y: 열, m: 질량, s: 속력, d: 방향
    // d: 0~7, ↑ 부터 시계방향
    int id, x, y, m, s, d;

    Atom(int id, int x, int y, int m, int s, int d) {
        this->id = id;
        this->x = x;
        this->y = y;
        this->m = m;
        this->s = s;
        this->d = d;
    }

    Atom() {
        this->id = -1;
        this->x = -1;
        this->y = -1;
        this->m = -1;
        this->s = -1;
        this->d = -1;
    }
};

int n, m, k, lastId, currentTime;
vector<Atom> atoms;
vector<Atom> grid[MAX][MAX];

void move() {
    vector<Atom> newGrid[MAX][MAX];

    for(Atom& a: atoms) {
        a.x += (dx[a.d] * a.s);
        a.y += (dy[a.d] * a.s);

        a.x = (a.x % n + n) % n;
        a.y = (a.y % n + n) % n;

        newGrid[a.x][a.y].emplace_back(a);
    }

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            grid[i][j].swap(newGrid[i][j]);
        }
    }
}

vector<Atom> split(const int x, const int y) {
    Atom combined;
    vector<Atom> splitted;

    int combinedM = 0, combinedS = 0;
    bool isAllOdd = true, isAllEven = true;

    for(const Atom& a: grid[x][y]) {
        combinedM += a.m;
        combinedS += a.s;

        if(a.d % 2 == 0) {
            isAllOdd = false;
        }

        if(a.d % 2 != 0) {
            isAllEven = false;
        }
    }

    combinedM /= 5;
    combinedS /= grid[x][y].size();

    if(combinedM == 0) {
        return splitted;
    }

    for(int i = 0; i < 4; i++) {
        int d;

        if(!isAllEven && !isAllOdd) {
            d = i * 2 + 1;
        } else {
            d = i * 2;
        }

        Atom target(++lastId, x, y, combinedM, combinedS, d);
        splitted.emplace_back(target);
    }

    return splitted;
}

void synthesis() {
    vector<Atom> newAtoms;
    vector<Atom> newGrid[MAX][MAX];

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(grid[i][j].size() >= 2) {
                vector<Atom> splitted = split(i, j);
                newAtoms.insert(newAtoms.end(), splitted.begin(), splitted.end());
                newGrid[i][j].insert(newGrid[i][j].end(), splitted.begin(), splitted.end());
            } else if(grid[i][j].size() == 1) {
                Atom target = grid[i][j][0];

                newAtoms.emplace_back(target);
                newGrid[i][j].emplace_back(target);
            }
        }
    }

    atoms = newAtoms;

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            grid[i][j].swap(newGrid[i][j]);
        }
    }
}

int getM() {
    int sum = 0;

    for(const Atom& a: atoms) {
        sum += a.m;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    lastId = 0;
    currentTime = 0;

    for(int i = 0; i < m; i++) {
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;

        Atom atom = Atom(i, --x, --y, m, s, d);
        atoms.emplace_back(atom);
        grid[x][y].emplace_back(atom);
        lastId = i;
    }

    while(true) {
        if(currentTime == k) {
            cout << getM() << "\n";
            break;
        }

        move();
        synthesis();
        currentTime++;
    }

    return 0;
}