#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<int>& visited, int node, int color) {
    visited[node] = color;

    for (int i: graph[node]) {
        if (!visited[i]) {
            dfs(graph, visited, i, color == 1 ? 2 : 1);
        }
    }
}

bool getResult(int v, vector<vector<int>>& graph, vector<int>& visited) {
    for (int i = 1; i <= v; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int next = graph[i][j];

            if (visited[i] == visited[next]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    while (k--) {
        int v, e;
        cin >> v >> e;

        vector<vector<int>> graph(v + 1);
        vector<int> visited(v + 1);

        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }

        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                dfs(graph, visited, i, 1);
            }
        }

        cout << (getResult(v, graph, visited) ? "YES\n" : "NO\n");
    }

    return 0;
}
