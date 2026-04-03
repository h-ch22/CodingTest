#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000 * 1000 + 1

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    int minCost = INF;

    for (int i = 0; i < 3; i++) {
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = INF;
        dp[0][1] = INF;
        dp[0][2] = INF;
        dp[0][i] = grid[0][i];

        for (int j = 1; j < n; j++) {
            dp[j][0] = min(dp[j - 1][1] + grid[j][0], dp[j - 1][2] + grid[j][0]);
            dp[j][1] = min(dp[j - 1][0] + grid[j][1], dp[j - 1][2] + grid[j][1]);
            dp[j][2] = min(dp[j - 1][0] + grid[j][2], dp[j - 1][1] + grid[j][2]);

            if (j == n - 1) {
                if (i == 0) {
                    minCost = min({ minCost, dp[j][1], dp[j][2] });;
                } else if (i == 1) {
                    minCost = min({ minCost, dp[j][0], dp[j][2] });
                } else {
                    minCost = min({ minCost, dp[j][0], dp[j][1] });
                }
            }
        }
    }

    cout << minCost << "\n";

    return 0;
}
