#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    int k;
    cin >> k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    vector<vector<pair<int, int>>> graph(v + 1);
    vector<int> dist(v + 1, numeric_limits<int>::max());

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].emplace_back(make_pair(b, w));
    }

    queue.emplace(make_pair(0, k));
    dist[k] = 0;

    while (!queue.empty()) {
        int cost = queue.top().first;
        int current = queue.top().second;
        queue.pop();

        if (dist[current] < cost) {
            continue;
        }

        for (int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i].first;
            int nextCost = graph[current][i].second;

            if (dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                queue.emplace(make_pair(dist[next], next));
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "INF" << "\n";
        } else {
            cout << dist[i] << "\n";
        }
    }

    return 0;
}
