#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct GridMap;
/*
d: 1 - 상, 2 - 하, 3 - 좌, 4 - 우
*/
int n, r, c, d, globalOrder;
vector<vector<GridMap>> grid;

const int DIRECTIONS[5][4] = {
    { 0, 0, 0, 0 },
    { 1, 3, 4, 2 },
    { 2, 4, 3, 1 },
    { 3, 2, 1, 4 },
    { 4, 1, 2, 3 }
};

const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { -1, 0, 1, 0 };

struct GridMap {
    int r, c, type, order;

    GridMap() {
        order = -1;
    }

    GridMap(const int r, const int c, const int type) {
        this->r = r;
        this->c = c;
        this->type = type;
        order = type == 0 ? 0 : -1;
    }

    void updateOrder() {
        order = ++globalOrder;
    }

    bool operator <(const GridMap& other) const {
        return order < other.order;
    }
};

pair<int, int> getDirection(const int dir) {
    switch(dir) {
        case 1:
            return make_pair(-1, 0);

        case 2:
            return make_pair(1, 0);

        case 3:
            return make_pair(0, -1);

        case 4:
            return make_pair(0, 1);

        default:
            return make_pair(0, 0);
    }
}

int getDirection(const pair<int, int> dir) {
    if(dir.first == -1) {
        return 1;
    }
    
    if(dir.first == 1) {
        return 2;
    }

    if(dir.second == -1) {
        return 3;
    }

    if(dir.second == 1) {
        return 4;
    }

    return 0;
}

bool goToAdjacentArea() {
    for(int i = 0; i < 4; i++) {
        const int currentD = DIRECTIONS[d][i];
        const pair<int, int> direction = getDirection(currentD);
        const int nr = r + direction.first, nc = c + direction.second;

        if(0 <= nr && nr < n && 0 <= nc && nc < n) {
            if(grid[nr][nc].order == 0) {            
                // cout << r << ", " << c << " -> " << nr << ", " << nc << " (" << d << " -> " << currentD << ")\n";
                r = nr;
                c = nc;
                d = currentD;

                grid[nr][nc].updateOrder();
                
                return true;
            }
        }
    }

    return false;
}

pair<int, int> getNearest() {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    vector<pair<int, int>> candidates;
    deque<pair<int, int>> queue;

    queue.emplace_back(r, c);
    dist[r][c] = 0;

    int shortest = 1e6;

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        for(int i = 0; i < 4; i++) {
            const int nr = current.first + dr[i], nc = current.second + dc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n && dist[nr][nc] == -1) {
                if(grid[nr][nc].type == 0) {
                    dist[nr][nc] = dist[current.first][current.second] + 1;
                    queue.emplace_back(nr, nc);

                    if(grid[nr][nc].order == 0) {
                        if(dist[nr][nc] < shortest) {
                            shortest = dist[nr][nc];
                            candidates.clear();
                            candidates.emplace_back(nr, nc);
                        } else if(dist[nr][nc] == shortest) {
                            candidates.emplace_back(nr, nc);
                        }
                    }
                } else {
                    dist[nr][nc] = 1e6;
                }
            }
        }
    }

    sort(candidates.begin(), candidates.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first) return a.second < b.second;

        return a.first < b.first;
    });

    // cout << "From: " << r << ", " << c << " To: " << candidates[0].first << ", " << candidates[0].second << "\n";

    return candidates[0];
}

void move(const pair<int, int> to) {
    deque<pair<int, int>> queue;
    queue.emplace_back(to.first, to.second);

    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[to.first][to.second] = 0;

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        for(int i = 0; i < 4; i++) {
            const int nr = current.first + dr[i], nc = current.second + dc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(grid[nr][nc].type == 0) {
                    if(dist[nr][nc] == -1) {
                        dist[nr][nc] = dist[current.first][current.second] + 1;
                        queue.emplace_back(nr, nc);
                    }
                } else {
                    dist[nr][nc] = 1e6;
                }
            }
        }
    }

    int currentR = r, currentC = c;

    while(true) {
        if(currentR == to.first && currentC == to.second) {
            r = currentR;
            c = currentC;

            break;
        }

        for(int i = 0; i < 4; i++) {
            const int nr = currentR + dr[i], nc = currentC + dc[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < n) {
                if(dist[nr][nc] == dist[currentR][currentC] - 1) {
                    currentR = nr;
                    currentC = nc;
                    d = getDirection(make_pair(dr[i], dc[i]));
                    
                    if(grid[nr][nc].order == 0) grid[nr][nc].updateOrder();
                    break;
                }
            }
        }
    }
}

bool checkAllSeaVisited() {
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
    grid.assign(n, vector<GridMap>(n));

    int current = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int type;
            cin >> type;

            grid[i][j] = GridMap(i, j, type);
        }
    }

    --r;
    --c;
    grid[r][c].updateOrder();

    while(true) {
        if(checkAllSeaVisited()) break;

        if(!goToAdjacentArea()) {
            pair<int, int> to = getNearest();
            move(to);
        }

        current++;
    }

    vector<GridMap> flatten;

    for(const auto& row: grid) {
        flatten.insert(flatten.end(), row.begin(), row.end());
    }

    sort(flatten.begin(), flatten.end());

    for(const GridMap& f: flatten) {
        if(f.type == 0) {
            cout << f.r + 1 << " " << f.c + 1 << "\n";
        }
    }

    return 0;
}