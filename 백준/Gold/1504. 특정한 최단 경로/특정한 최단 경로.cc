#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 200000000

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start, int end) {
    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.emplace(make_pair(0, start));
    dist[start] = 0;

    while (!queue.empty()) {
        int cost = queue.top().first;
        int node = queue.top().second;
        queue.pop();

        if (dist[node] < cost) {
            continue;
        }

        for (pair<int, int> p: graph[node]) {
            int nextNode = p.first;
            int nextCost = cost + p.second;

            if (dist[nextNode] > nextCost) {
                dist[nextNode] = nextCost;
                queue.emplace(make_pair(nextCost, nextNode));
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].emplace_back(make_pair(b, c));
        graph[b].emplace_back(make_pair(a, c));
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> fromStart = dijkstra(graph, 1, n);
    vector<int> fromV1 = dijkstra(graph, v1, n);
    vector<int> fromV2 = dijkstra(graph, v2, n);

    int costFromV1 = fromStart[v1] + fromV1[v2] + fromV2[n];
    int costFromV2 = fromStart[v2] + fromV2[v1] + fromV1[n];

    if (costFromV1 >= INF && costFromV2 >= INF) {
        cout << -1 << "\n";
    } else {
        cout << min(costFromV1, costFromV2) << "\n";
    }

    return 0;
}
