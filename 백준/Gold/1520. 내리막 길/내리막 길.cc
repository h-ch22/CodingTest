#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dfs(vector<vector<int>>& graph, vector<vector<int>>& dp, int x, int y) {
	int m = graph.size();
	int n = graph[0].size();
	
	if(y == m - 1 && x == n - 1) {
		return 1;
	}
	
	if(dp[y][x] != -1) {
	    return dp[y][x];
	}
	
	dp[y][x] = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
		if(0 <= nx && nx < n && 0 <= ny && ny < m) {
			if(graph[ny][nx] < graph[y][x]) {
			    dp[y][x] += dfs(graph, dp, nx, ny);
			}
		}
    }
    
	return dp[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n;
	cin >> m >> n;

	vector<vector<int>> graph(m, vector<int>(n));
	vector<vector<int>> dp(m, vector<int>(n, -1));

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	cout << dfs(graph, dp, 0, 0) << "\n";

	return 0;
}
