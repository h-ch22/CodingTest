#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // Horizontal: 0, Vertical: 1, Diagonal: 2
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3)));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }

    dp[1][2][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j <= 2) {
                continue;
            }

            if (grid[i][j] == 1) {
                continue;
            }

            for (int k = 0; k < 3; k++) {
                if (k == 0) {
                    dp[i][j][k] = dp[i][j - 1][k] + dp[i][j - 1][2];
                } else if (k == 1) {
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j][2];
                } else {
                    if (grid[i - 1][j] == 1 || grid[i][j - 1] == 1) {
                        continue;
                    }

                    dp[i][j][k] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][k];
                }
            }
        }
    }

    int totalCounts = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << totalCounts << "\n";

    return 0;
}
