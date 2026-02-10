#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int order = 1;

void bfs(const vector<vector<int>>& graph, vector<int>& visited, int start) {
    deque<int> queue;
    queue.emplace_back(start);
    visited[start] = order;

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for (int v: graph[u]) {
            if (visited[v] == 0) {
                order++;
                visited[v] = order;
                queue.emplace_back(v);
            }
        }
    }

    for (int i = 1; i < visited.size(); i++) {
        cout << visited[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> graph(n + 1);
    vector<int> visited(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (vector<int>& v: graph) {
        sort(v.begin(), v.end());
    }

    bfs(graph, visited, r);

    return 0;
}
