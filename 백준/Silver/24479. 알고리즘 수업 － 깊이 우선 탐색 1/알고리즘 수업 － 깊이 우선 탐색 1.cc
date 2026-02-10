#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int order = 1;

void dfs(const vector<vector<int>>& graph, vector<int>& visited, const int r) {
    visited[r] = order;

    for (int i: graph[r]) {
        if (visited[i] == 0) {
            order++;
            dfs(graph, visited, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> graph(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (vector<int>& g: graph) {
        sort(g.begin(), g.end());
    }

    vector<int> visited(n + 1, 0);
    dfs(graph, visited, r);

    for (int i = 1; i <= n; i++) {
        cout << visited[i] << "\n";
    }

    return 0;
}
