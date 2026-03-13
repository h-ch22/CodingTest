#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(vector<string>& grid, vector<vector<int>>& dp, vector<vector<bool>>& visited, int x, int y) {
    if(dp[y][x] != -1) {
        return dp[y][x];
    }
    
    visited[y][x] = true;

    int current = grid[y][x] - '0';
    dp[y][x] = 0;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i] * current;
        int ny = y + dy[i] * current;
        
        if(0 <= nx && nx < grid[0].size() && 0 <= ny && ny < grid.size()) {
            if(grid[ny][nx] != 'H') {
                if(visited[ny][nx]) {
                    cout << -1 << "\n";
                    exit(0);
                }
                
                dp[y][x] = max(dp[y][x], dfs(grid, dp, visited, nx, ny) + 1);
            }
        }
    }
    
    visited[y][x] = false;
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<vector<bool>> visited(n, vector<bool>(m));
    
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    cout << dfs(grid, dp, visited, 0, 0) + 1 << "\n";
    
    return 0;
}
