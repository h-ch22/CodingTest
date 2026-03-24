#include <iostream>
#include <vector>
#include <deque>
#define MAX 1000000000

using namespace std;

bool canCross(const int start, const int end, const int mid, const int n, const vector<vector<pair<int, int>>>& graph) {
    vector<bool> visited(n + 1, false);
    deque<int> queue;

    queue.emplace_back(start);
    visited[start] = true;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop_front();

        if (current == end) {
            return true;
        }

        for (const auto& edge: graph[current]) {
            const int next = edge.first;
            const int limit = edge.second;

            if (!visited[next] && limit >= mid) {
                visited[next] = true;
                queue.emplace_back(next);
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int low = 1;
    int high = MAX;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(b, c));
        graph[b].emplace_back(make_pair(a, c));
    }

    int start, end;
    cin >> start >> end;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canCross(start, end, mid, n, graph)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << (low + high) / 2 << "\n";

    return 0;
}
