#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void bfs(vector<int>& graph, const int n, const int k) {
    deque<int> queue;
    queue.emplace_back(n);

    while (!queue.empty()) {
        int current = queue.front();

        if (current == k) {
            cout << graph[current] << "\n";
            break;
        }

        queue.pop_front();

        int nextPositionsN[3] = { current * 2, current + 1, current - 1 };

        for (int i = 0; i < 3; i++) {
            if (nextPositionsN[i] >= 0 && nextPositionsN[i] <= 100000 && graph[nextPositionsN[i]] == 0 && nextPositionsN[i] != n) {
                graph[nextPositionsN[i]] = graph[current] + 1;
                queue.emplace_back(nextPositionsN[i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> graph(100001, 0);
    bfs(graph, n, k);

    return 0;
}
