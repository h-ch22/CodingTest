#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;

    vector<int> matrix(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;

        if (i < n) {
            dp[i][i + 1] = matrix[i - 1] == matrix[i] ? 1 : 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[j][j + i] == -1) {
                dp[j][j + i] = matrix[j - 1] == matrix[j + i - 1] && dp[j + 1][j + i - 1] == 1 ? 1 : 0;
            }
        }
    }

    cin >> m;

    while (m--) {
        int s, e;
        cin >> s >> e;

        cout << dp[s][e] << "\n";
    }

    return 0;
}
