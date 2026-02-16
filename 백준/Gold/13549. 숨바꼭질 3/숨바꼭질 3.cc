#include <iostream>
#include <vector>
#include <queue>

#define MAX 200000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> visited(MAX, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    queue.emplace(make_pair(0, n));

    while (!queue.empty()) {
        const int cost = queue.top().first;
        const int node = queue.top().second;
        visited[node] = true;
        queue.pop();

        if (node == k) {
            cout << cost << "\n";
            break;
        }

        if (node < 0) {
            continue;
        }

        if (0 <= 2 * node && 2 * node <= MAX && !visited[2 * node]) {
            queue.emplace(make_pair(cost, 2 * node));
        }

        if (node - 1 >= 0 && node - 1 <= MAX && !visited[node - 1]) {
            queue.emplace(make_pair(cost + 1, node - 1));
        }

        if (node + 1 >= 0 && node + 1 <= MAX && !visited[node + 1]) {
            queue.emplace(make_pair(cost + 1, node + 1));
        }
    }

    return 0;
}
