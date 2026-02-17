#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, const int s, const int d) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    vector<int> dist(graph.size(), numeric_limits<int>::max());
    queue.emplace(make_pair(0, s));
    dist[s] = 0;

    while (!queue.empty()) {
        const int cost = queue.top().first;
        const int node = queue.top().second;
        queue.pop();

        if (dist[node] < cost) {
            continue;
        }

        for (pair<int, int> p: graph[node]) {
            const int nextNode = p.first;
            const int nextCost = cost + p.second;

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

    int T;
    cin >> T;

    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;

        vector<vector<pair<int, int>>> graph(n + 1);
        vector<int> candidates;

        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;

            graph[a].emplace_back(make_pair(b, d));
            graph[b].emplace_back(make_pair(a, d));
        }

        for (int i = 0; i < t; i++) {
            int x;
            cin >> x;

            vector<int> distFromS = dijkstra(graph, s, x);
            vector<int> distFromH = dijkstra(graph, h, x);
            vector<int> distFromG = dijkstra(graph, g, x);
            int shortest = distFromS[x];
            int routeA = distFromS[g] + distFromG[h] + distFromH[x];
            int routeB = distFromS[h] + distFromH[g] + distFromG[x];

            if (routeA == shortest || routeB == shortest) {
                candidates.emplace_back(x);
            }
        }

        sort(candidates.begin(), candidates.end());

        for (int i: candidates) {
            cout << i << " ";
        }

        cout << "\n";
    }

    return 0;
}
