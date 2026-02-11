#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i: graph[node]) {
        if (!visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    deque<int> queue;
    queue.emplace_back(node);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop_front();
        cout << current << " ";

        for (int i: graph[current]) {
            if (!visited[i]) {
                visited[i] = true;
                queue.emplace_back(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    for (vector<int>& g: graph) {
        sort(g.begin(), g.end());
    }

    vector<bool> visited(n + 1);
    dfs(graph, visited, v);
    visited = vector<bool>(n + 1);
    cout << "\n";
    bfs(graph, visited, v);

    return 0;
}
