#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct Cell;
int n, r, c, d, globalOrder;
vector<vector<Cell>> grid;

const int DIRECTIONS[5][4] = {
    { 0, 0, 0, 0 },
    { 1, 3, 4, 2 },
    { 2, 4, 3, 1 },
    { 3, 2, 1, 4 },
    { 4, 1, 2, 3 }
};

const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { -1, 0, 1, 0 };

struct Cell {
    int r, c, order;
    bool isReef;

    Cell() {
        order = 1e6;
        isReef = true;
    }

    Cell(const int r, const int c, const bool isReef) {
        this->r = r;
        this->c = c;
        this->isReef = isReef;
        this->order = isReef ? 1e6 : 0;
    }

    void updateOrder() {
        if(isReef) return;

        order = ++globalOrder;
    }

    bool operator <(const Cell& other) const {
        return order < other.order;
    }
};

pair<int, int> getNextDirections(const int d) {
    switch(d) {
        case 1:
            return { -1, 0 };

        case 2:
            return { 1, 0 };

        case 3:
            return { 0, -1 };

        case 4:
            return { 0, 1 };

        default:
            return { 0, 0 };
    }
}

int getNewDirection(const pair<int, int> d) {
    if(d.first == -1) {
        return 1;
    }

    if(d.first == 1) {
        return 2;
    }

    if(d.second == -1) {
        return 3;
    }

    if(d.second == 1) {
        return 4;
    }

    return 0;
}

bool experienceToAdjacent() {
    int currentD = d;

    for(int i = 0; i < 4; i++) {
        const int newD = DIRECTIONS[d][i];
        const pair<int, int> nextDir = getNextDirections(newD);
        const int nr = nextDir.first + r, nc = nextDir.second + c;

        if(0 <= nr && nr < n && 0 <= nc && nc < n) {
            if(grid[nr][nc].isReef || grid[nr][nc].order > 0) continue;

            // cout << "From " << r << ", " << c << " to " << nr << ", " << nc << "\n";

            d = newD;
            r = nr;
            c = nc;
            grid[nr][nc].updateOrder();

            return true;
        }
    }

    return false;
}

pair<int, int> getShortestPlace() {
    deque<pair<int, int>> queue;
    vector<vector<int>> dist(n, vector<int>(n, -1));

    dist[r][c] = 0;
    queue.emplace_back(r, c);

    int minDist = 1e6;
    vector<pair<int, int>> candidates;

    bool shouldBreak = false;

    while(!queue.empty()) {
        if(shouldBreak) break;
        
        const pair<int, int> current = queue.front();
        queue.pop_front();

        const int cr = current.first, cc = current.second;

        for(int i = 0; i < 4; i++) {
            const int nr = cr + dr[i], nc = cc + dc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(grid[nr][nc].isReef) {
                    dist[nr][nc] = 1e6;
                    continue;
                }

                if(dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[cr][cc] + 1;
                    queue.emplace_back(nr, nc);

                    if(grid[nr][nc].order == 0) {      
                        if(dist[nr][nc] > minDist) shouldBreak = true;

                        if(dist[nr][nc] < minDist) {
                            candidates.clear();
                            minDist = dist[nr][nc];
                            candidates.emplace_back(nr, nc);
                        } else if(dist[nr][nc] == minDist) {
                            candidates.emplace_back(nr, nc);
                        }
                    }
                }
            }
        }
    }

    sort(candidates.begin(), candidates.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first) return a.second < b.second;
        
        return a.first < b.first;
    }); 

    for(const pair<int, int>& c: candidates) {
        if(c.first == r && c.second == ::c) continue;

        return c;
    }

    return { 0, 0 };
}

void moveToPlace(const pair<int, int> target) {
    deque<pair<int, int>> queue;
    vector<vector<int>> dist(n, vector<int>(n, -1));

    const int tr = target.first, tc = target.second;
    dist[tr][tc] = 0;

    queue.emplace_back(tr, tc);

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        const int cr = current.first, cc = current.second;

        queue.pop_front();

        for(int i = 0; i < 4; i++) {
            const int nr = cr + dr[i], nc = cc + dc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(grid[nr][nc].isReef) {
                    dist[nr][nc] = 1e6;
                    continue;
                }

                if(dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[cr][cc] + 1;
                    queue.emplace_back(nr, nc);
                }
            }
        }
    }

    int currentR = r, currentC = c, currentD = d;

    while(true) {
        if(currentR == tr && currentC == tc) {
            r = tr, c = tc, d = currentD;
            break;
        }

        for(int i = 0; i < 4; i++) {
            const int nr = currentR + dr[i], nc = currentC + dc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(grid[nr][nc].isReef) continue;

                if(dist[nr][nc] == dist[currentR][currentC] - 1) {
                    currentR = nr, currentC = nc, currentD = getNewDirection({ dr[i], dc[i] });

                    if(grid[nr][nc].order == 0) {
                        grid[nr][nc].updateOrder();
                    }

                    break;
                }
            }
        }
    }
}

bool checkAllCellExperienced() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j].order == 0) return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    globalOrder = 0;
    cin >> n >> r >> c >> d;

    grid.assign(n, vector<Cell>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int type;
            cin >> type;

            grid[i][j] = Cell(i, j, type == 1);
        }
    }

    --r;
    --c;

    grid[r][c].updateOrder();

    while(true) {
        if(checkAllCellExperienced()) break;

        if(!experienceToAdjacent()) {
            const pair<int, int> target = getShortestPlace();
            // cout << "From " << r << ", " << c << " To " << target.first << ", " << target.second << "\n";

            moveToPlace(target);
        }
    }

    vector<Cell> flatten;

    for(int row = 0; row < n; row++) {
        flatten.insert(flatten.end(), grid[row].begin(), grid[row].end());
    }

    sort(flatten.begin(), flatten.end());

    for(const Cell& f: flatten) {
        if(f.isReef) continue;

        cout << f.r + 1 << " " << f.c + 1 << "\n";
    }

    return 0;
}