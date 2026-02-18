#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, MAX));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a][b] = min(graph[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == MAX) {
                cout << 0 << " ";
            } else {
                cout << graph[i][j] << " ";
            }
        }

        cout << "\n";
    }

    cout << "\n";

    return 0;
}
