#include <iostream>
#include <vector>

#define MAX 10000000

using namespace std;

void bellmanFord(const vector<vector<pair<int, int>>>& graph, const int start) {
    vector<long long> dist( graph.size(), MAX);
    dist[start] = 0;

    for (int i = 0; i < graph.size() - 1; i++) {
        for (int j = 0; j < graph.size(); j++) {
            for (const pair<int, int>& p: graph[j]) {
                const int nextNode = p.first;
                const int nextCost = p.second;

                if (dist[j] != MAX &&
                    dist[nextNode] > nextCost + dist[j]) {
                    dist[nextNode] = nextCost + dist[j];
                }
            }
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        for (const pair<int, int>& p: graph[i]) {
            const int node = p.first;
            const int cost = p.second;

            if (dist[node] == MAX) {
                continue;
            }

            if (dist[node] > cost + dist[i]) {
                cout << -1 << "\n";
                return;
            }
        }
    }

    for (int i = start + 1; i < dist.size(); i++) {
        cout << (dist[i] < MAX / 2 ? dist[i] : -1) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].emplace_back(make_pair(b, c));
    }

    bellmanFord(graph, 1);

    return 0;
}
