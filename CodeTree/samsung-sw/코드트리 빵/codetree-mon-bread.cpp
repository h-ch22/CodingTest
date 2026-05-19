#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define MAX_DIST 30

using namespace std;

int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

int n, m;
vector<vector<int>> grid; // 0: 빈 칸, 1: 베이스캠프, 2: 벽 (진입불가)
vector<pair<int, int>> stores;
vector<pair<int, int>> people;
vector<pair<int, int>> camp;

vector<vector<int>> getStoreDistance(const int x, const int y) {
    deque<pair<int, int>> queue;
    vector<vector<int>> distance(n, vector<int>(n, -1));

    distance[x][y] = 0;
    queue.emplace_back(x, y);

    while(!queue.empty()) {
        const pair<int, int> current = queue.front();
        queue.pop_front();

        for(int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                if(grid[nx][ny] < 2 && distance[nx][ny] == -1) {
                    distance[nx][ny] = distance[current.first][current.second] + 1;
                    queue.emplace_back(nx, ny);
                }
            }
        }
    }

    return distance;
}

bool isStore(const int x, const int y) {
    for(const pair<int, int>& s: stores) {
        if(s.first == x && s.second == y) {
            return true;
        }
    }

    return false;
}

void movePerson(const int peopleIdx, const vector<vector<int>>& distance) {
    int minStep = MAX_DIST;
    pair<int, int> toMove;

    for(int i = 0; i < 4; i++) {
        int nx = people[peopleIdx].first + dx[i];
        int ny = people[peopleIdx].second + dy[i];

        if(0 <= nx && nx < n && 0 <= ny && ny < n) {
            if(distance[nx][ny] < minStep && distance[nx][ny] != -1) {
                minStep = distance[nx][ny];
                toMove.first = nx;
                toMove.second = ny;
            }
        }
    }

    people[peopleIdx] = toMove;
}

void moveToShortestCamp(const int peopleIdx, const vector<vector<int>>& distance) {
    int minStep = MAX_DIST;
    vector<pair<int, int>> mins;

    for(int i = 0; i < camp.size(); i++) {
        int cx = camp[i].first, cy = camp[i].second;
        int dist = distance[cx][cy];

        if(dist < minStep && dist != -1 && grid[cx][cy] != 2) {
            minStep = dist;
            mins.clear();
            mins.emplace_back(cx, cy);
        } else if(dist == minStep) {
            mins.emplace_back(cx, cy);
        }
    }

    sort(mins.begin(), mins.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first) {
            return a.second < b.second;
        }

        return a.first < b.first;
    });

    people[peopleIdx].first = mins[0].first;
    people[peopleIdx].second = mins[0].second;

    grid[mins[0].first][mins[0].second] = 2;
}

void block() {
    for(int i = 0; i < m; i++) {
        int personX = people[i].first, personY = people[i].second;
        int storeX = stores[i].first, storeY = stores[i].second;

        if(personX == storeX && personY == storeY) {
            grid[personX][personY] = 2;
        }
    }
}

bool isAllPeopleInStore() {
    for(int i = 0; i < m; i++) {
        int personX = people[i].first, personY = people[i].second;
        int storeX = stores[i].first, storeY = stores[i].second;

        if(personX != storeX || personY != storeY) {
            return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n, vector<int>(n));
    stores.resize(m);
    people.resize(m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int f;
            cin >> f;

            if(f == 1) {
                camp.emplace_back(i, j);
            }

            grid[i][j] = f;
        }
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        stores[i].first = x - 1;
        stores[i].second = y - 1;
    }

    for(int i = 0; i < m; i++) {
        people[i].first = -1;
        people[i].second = -1;
    }

    int t = 0;

    // for(const pair<int, int>& s: stores) {
    //     cout << s.first << " " << s.second << "\n";
    // }

    while(true) {
        // 모든 사람들이 편의점에 진입하면 종료
        if(isAllPeopleInStore()) {
            cout << t << "\n";
            break;
        }

        // 1 ~ m번 사람까지 편의점을 향해 한 칸 전진
        for(int i = 0; i < (t < m ? t : m); i++) {
            if(people[i].first > -1 && people[i].second > -1 && people[i] != stores[i]) {
                vector<vector<int>> distance = getStoreDistance(stores[i].first, stores[i].second);
                movePerson(i, distance);
            }
        }

        // 사람들이 모두 움직인 후 해당 위치가 편의점이라면 벽을 세움
        block();

        // t번 사람을 가장 가까이 있는 베이스 캠프로 넣기
        if(t < m) {
            vector<vector<int>> distance = getStoreDistance(stores[t].first, stores[t].second);
            moveToShortestCamp(t, distance);
        }

        t++;
    }

    return 0;
}
