#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
    visited[start] = true;

    for (int g: graph[start]) {
        if (!visited[g]) {
            dfs(graph, visited, g);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    dfs(graph, visited, 1);
    cout << count(visited.begin(), visited.end(), true) - 1 << "\n";

    return 0;
}
