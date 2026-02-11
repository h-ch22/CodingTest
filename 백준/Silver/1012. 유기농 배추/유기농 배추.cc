#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(vector<vector<int>>& graph, int x, int y) {
    graph[y][x] = 2;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < graph[0].size() && ny >= 0 && ny < graph.size()) {
            if (graph[ny][nx] == 1) {
                dfs(graph, nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int caseNum = 0;

    while (caseNum < t) {
        int m, n, k;
        cin >> m >> n >> k;

        int count = 0;

        vector<vector<int>> graph(n, vector<int>(m));

        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;

            graph[v][u] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 1) {
                    dfs(graph, j, i);
                    count++;
                }
            }
        }

        cout << count << "\n";
        caseNum++;
    }

    return 0;
}
