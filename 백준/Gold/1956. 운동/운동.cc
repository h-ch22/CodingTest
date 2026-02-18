#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v + 1, vector<int>(v + 1, MAX));

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    int minCycle = MAX;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i != j) {
                if (graph[i][j] < MAX && graph[j][i] < MAX) {
                    minCycle = min(minCycle, graph[i][j] + graph[j][i]);
                }
            }
        }
    }

    cout << (minCycle >= MAX ? -1 : minCycle) << "\n";

    return 0;
}
