#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define MIN 1e6

using namespace std;

int n, m, t;
vector<vector<int>> grid; // 0: 빈 공간, 1: 베이스캠프, -1: 이동할 수 없는 구역
vector<pair<int, int>> stores; // { x, y } - x: 행, y: 열
vector<pair<int, int>> people; // { x, y }
vector<pair<int, int>> camps; // { x, y }

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

vector<vector<int>> getDistance(const int x, const int y) {
    deque<pair<int, int>> queue;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    dist[x][y] = 0;

    queue.emplace_back(x, y);

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        for(int i = 0; i < 4; i++) {
            const int nx = current.first + dx[i];
            const int ny = current.second + dy[i];

            if(0 < nx && nx <= n && 0 < ny && ny <= n && dist[nx][ny] == -1 && grid[nx][ny] != -1) {
                dist[nx][ny] = dist[current.first][current.second] + 1;
                queue.emplace_back(nx, ny);
            }
        }
    }

    return dist;
}

void move(const int idx, const vector<vector<int>>& dist) {
    int minDist = MIN;
    int toX = people[idx].first, toY = people[idx].second;
    
    for(int i = 0; i < 4; i++) {
        const int nx = people[idx].first + dx[i];
        const int ny = people[idx].second + dy[i];

        if(0 < nx && nx <= n && 0 < ny && ny <= n && dist[nx][ny] > -1 && grid[nx][ny] != -1) {
            if(dist[nx][ny] < minDist) {
                minDist = dist[nx][ny];
                toX = nx, toY = ny;
            }
        }
    }

    people[idx] = { toX, toY };
}

void goToBase() {
    vector<vector<int>> dist = getDistance(stores[t].first, stores[t].second);
    int minDist = MIN;
    vector<pair<int, int>> shortest;

    for(const pair<int, int> c: camps) {
        const int nx = c.first;
        const int ny = c.second;

        if(grid[nx][ny] == 1 && dist[nx][ny] > -1) {
            if(dist[nx][ny] < minDist) {
                shortest.clear();
                shortest.emplace_back(nx, ny);
                minDist = dist[nx][ny];
            } else if(dist[nx][ny] == minDist) {
                shortest.emplace_back(nx, ny);
            }
        } 
    }

    sort(shortest.begin(), shortest.end(), [](const pair<int, int> a, const pair<int, int> b){
        if(a.first == b.first) {
            return a.second < b.second;
        }

        return a.first < b.first;
    });

    people[t] = shortest[0];
    grid[shortest[0].first][shortest[0].second] = -1;
}

void disableArea() {
    for(int i = 0; i < m; i++) {
        if(people[i] == stores[i]) {
            grid[people[i].first][people[i].second] = -1;    
        }
    }
}

bool isAllPeopleInStore() {
    for(int i = 0; i < m; i++) {
        if(people[i] != stores[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    grid.assign(n + 1, vector<int>(n + 1));
    stores.assign(m, { -1, -1 });
    people.assign(m, { 0, 0 });

    t = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int state;
            cin >> state;

            if(state == 1) {
                camps.emplace_back(i, j);
            }

            grid[i][j] = state;
        }
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        stores[i] = { x, y };
    }

    while(true) {
        if(isAllPeopleInStore()) {
            cout << t << "\n";
            break;
        }

        for(int i = 0; i < m; i++) {
            if(people[i].first > 0 && people[i].second > 0 && people[i] != stores[i]) {
                vector<vector<int>> dist = getDistance(stores[i].first, stores[i].second);
                move(i, dist);
            }
        }

        disableArea();

        if(t < m && people[t] != stores[t]) {
            goToBase();
        }

        t++;
    }

    return 0;
}