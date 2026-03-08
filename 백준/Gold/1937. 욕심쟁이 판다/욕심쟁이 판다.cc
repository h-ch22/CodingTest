#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(vector<vector<int>>& graph, vector<vector<int>>& dp, int x, int y) {
    int w = graph[0].size();
    int h = graph.size();
    
    if(dp[y][x] != -1) {
        return dp[y][x];
    }
    
    dp[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(0 <= nx && nx < w && 0 <= ny && ny < h) {
            if(graph[ny][nx] > graph[y][x]) {
                dp[y][x] = max(dp[y][x], dfs(graph, dp, nx, ny) + 1);
            }
        }
    }
    
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    int maxBamboo = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            maxBamboo = max(maxBamboo, dfs(graph, dp, j, i));
        }
    }
    
    cout << maxBamboo << "\n";
    
    return 0;
}
