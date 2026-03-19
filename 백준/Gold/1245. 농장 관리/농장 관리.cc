#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int dx[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void bfs(int y, int x, int& count, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
    deque<pair<int, int>> queue;
    queue.emplace_back(make_pair(y, x));
    visited[y][x] = true;
    bool isPeak = true;

    while(!queue.empty()) {
        pair<int, int> target = queue.front();
        queue.pop_front();
        
        for(int i = 0; i < 8; i++) {
            int ny = target.first + dy[i];
            int nx = target.second + dx[i];
            
            if(0 <= ny && ny < heights.size() && 0 <= nx && nx < heights[0].size()) {
                if(heights[target.first][target.second] < heights[ny][nx]) {
                    isPeak = false;
                }
                
                if(!visited[ny][nx] && heights[target.first][target.second] == heights[ny][nx]) {
                    visited[ny][nx] = true;
                    queue.emplace_back(make_pair(ny, nx));
                }
            }
        }
    }
    
    if(isPeak) {
        count++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> heights(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> heights[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                bfs(i, j, count, heights, visited);
            }
        }
    }
    
    cout << count << "\n";
    
    return 0;
}
