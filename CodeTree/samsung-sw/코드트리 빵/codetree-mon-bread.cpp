#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int n, m, currentTurn;
vector<vector<int>> grid; // 0: 빈 공간, 1: 베이스캠프, 2: 지나갈 수 없는 구역
vector<pair<int, int>> stores;
vector<pair<int, int>> camps;
vector<pair<int, int>> people;

int dx[4] = { -1, 0, 0, 1 }; // 세로
int dy[4] = { 0, -1, 1, 0 }; // 가로

/*
* getDistance(int x, int y): vector<vector<int>>
* x: 가고자 하는 곳의 x
* y: 가고자 하는 곳의 y
* 해당 좌표를 기준으로 모든 좌표에 대해 거리를 반환한다.
*/
vector<vector<int>> getDistance(const int x, const int y) {
    deque<pair<int, int>> queue;
    queue.emplace_back(x, y);

    vector<vector<int>> distance(n, vector<int>(n, -1));
    distance[x][y] = 0;

    while(!queue.empty()) {
        pair<int, int> current = queue.front();
        queue.pop_front();

        for(int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            
            if(nx == x && ny == y) {
                continue;
            }

            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(grid[nx][ny] != 2 && distance[nx][ny] == -1) {
                    distance[nx][ny] = distance[current.first][current.second] + 1;
                    queue.emplace_back(nx, ny);
                }
            }
        }
    }

    return distance;
}

/*
* getShortestPlace(vector<vector<int>> distance, int x, int y): pair<int, int>
* vector<vector<int>> distance: 가고자 하는 곳을 기준으로 모든 맵의 거리
* int x: 현재 x
* int y: 현재 y
* 현재 x, y를 기준으로 가장 가까운 좌표를 반환한다.
*/
pair<int, int> getShortestPlace(const vector<vector<int>>& distance, const int x, const int y) {
    int shortest = 15 * 15;
    pair<int, int> result = { -1, -1 };
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 <= nx && nx < n && 0 <= ny && ny < n) {
            if(distance[nx][ny] < shortest && distance[nx][ny] != -1) {
                shortest = distance[nx][ny];
                result = { nx, ny };
            }
        }
    }

    return result;
}

/*
* block(int x, int y): void
* x: 막고자 하는 구역의 x
* y: 막고자 하는 구역의 y
* x, y를 지나갈 수 없도록 막는다.
*/
void block(const int x, const int y){
    grid[x][y] = 2;
}

/*
* getAllPeopleInStore(): void
* 모든 사람이 스토어에 진입했는지 확인한 결과를 반환한다.
*/

bool getAllPeopleInStore() {
    for(int i = 0; i < m; i++) {
        if(people[i] != stores[i]) {
            return false;
        }
    }

    return true;
}

/*
* getShortestCamp(vector<vector<int>>& distance, int x, int y): pair<int, int>
* vector<vector<int>> distance: 가고자 하는 곳을 기준으로 맵 전역의 거리
* 가고자 하는 곳을 기준으로 가장 가까운 캠프의 위치를 반환한다.
*/
pair<int, int> getShortestCamp(const vector<vector<int>>& distance) {
    int shortest = 15 * 15;
    vector<pair<int, int>> shortestPaths;

    for(const pair<int, int> c: camps) {
        const int distX = c.first;
        const int distY = c.second;

        if(grid[distX][distY] < 2) {
            if(distance[distX][distY] < shortest && distance[distX][distY] != -1) {
                shortest = distance[distX][distY];
                shortestPaths.clear();
                shortestPaths.emplace_back(distX, distY);
            } else if(distance[distX][distY] == shortest) {
                shortestPaths.emplace_back(distX, distY);
            }
        }
    }

    if(shortestPaths.size() == 1) {
        return shortestPaths[0];
    } else {
        sort(shortestPaths.begin(), shortestPaths.end(), [](const pair<int, int> a, const pair<int, int> b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }

            return a.first < b.first;
        });

        return shortestPaths[0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n, vector<int>(n));
    stores.resize(m);
    people.resize(m);

    currentTurn = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;

            if(tmp == 1) {
                camps.emplace_back(i, j);
            }

            grid[i][j] = tmp;
        }
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        stores[i] = { x - 1, y - 1 };
        people[i] = { -1, -1 };
    }

    while(true) {
        // 1. 모든 사람이 편의점에 진입했는지 확인하고, 진입했으면 멈춘다.
        if(getAllPeopleInStore()) {
            cout << currentTurn - 1 << "\n";
            break;
        }

        // 2-1. 격자에 있는 사람들 중 편의점에 있지 않는 모두를 편의점 방향으로 1칸 움직인다.
        int range = (currentTurn < m) ? currentTurn : m;
        vector<pair<int, int>> toBlock(range);

        for(int i = 0; i < range; i++) {
            if(stores[i] != people[i]) {
                vector<vector<int>> distance = getDistance(stores[i].first, stores[i].second);
                int humanX = people[i].first, humanY = people[i].second;
                
                if(humanX < 0 || humanY < 0) {
                    continue;
                }
    
                pair<int, int> shortest = getShortestPlace(distance, humanX, humanY);
                toBlock[i] = shortest;
                people[i] = shortest;
            }
        }

        // 2-2. 격자에 있는 사람들이 모두 움직이고 나면 해당 좌표를 막는다.
        for(int i = 0; i < range; i++) {
            if(stores[i] == toBlock[i]) {
                block(toBlock[i].first, toBlock[i].second);
            }
        }

        // 3. 현재 시간이 t <= m일 때 t번 사람이 편의점에 있지 않는 경우 t번 사람을 가까이 있는 베이스 캠프로 진입시킨다.
        if(currentTurn <= m) {
            if(stores[currentTurn - 1] != people[currentTurn - 1]) {
                vector<vector<int>> distance = getDistance(stores[currentTurn - 1].first, stores[currentTurn - 1].second);
                pair<int, int> toGo = getShortestCamp(distance);
                people[currentTurn - 1] = toGo;
                block(toGo.first, toGo.second);
            }
        }

        // 4. 현재 시간 증가
        currentTurn++;
    }

    return 0;
}
