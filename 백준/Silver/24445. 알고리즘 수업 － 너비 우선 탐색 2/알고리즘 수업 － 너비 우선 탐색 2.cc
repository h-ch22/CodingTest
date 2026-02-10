#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int order = 1;

void bfs(const vector<vector<int>>& graph, vector<int>& visited, int start) {
    deque<int> queue;
    visited[start] = order;
    queue.emplace_back(start);

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop_front();

        for (int i: graph[node]) {
            if (visited[i] == 0) {
                order++;
                visited[i] = order;
                queue.emplace_back(i);
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

    for (vector<int>& g: graph) {
        sort(g.begin(), g.end(), greater<>());
    }

    bfs(graph, visited, r);

    return 0;
}
