#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void bfs(const vector<int>& graph) {
    deque<int> queue;
    vector<int> visited(101);

    queue.emplace_back(1);

    while (!queue.empty()) {
        const int node = queue.front();
        queue.pop_front();

        if (node == 100) {
            cout << visited[100] << "\n";
            return;
        }

        for (int i = 1; i <= 6; i++) {
            int nextNode = node + i;

            if (nextNode <= 100 && !visited[nextNode]) {
                if (graph[nextNode]) {
                    if (!visited[graph[nextNode]]) {
                        nextNode = graph[nextNode];
                        visited[nextNode] = visited[node] + 1;
                        queue.emplace_back(nextNode);
                    }
                } else if (!visited[nextNode]) {
                    visited[nextNode] = visited[node] + 1;
                    queue.emplace_back(nextNode);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> graph(101);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        graph[x] = y;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u] = v;
    }

    bfs(graph);

    return 0;
}
