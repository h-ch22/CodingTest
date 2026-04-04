#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c;
    cin >> n >> m >> c;

    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    vector<vector<vector<vector<int>>>> dp(
        vector<vector<vector<vector<int>>>>(n + 1, vector<vector<vector<int>>>(m + 1,
            vector<vector<int>>(c + 1, vector<int>(c + 1))
        ))
    );

    for (int i = 0; i < c; i++) {
        int x, y;
        cin >> x >> y;

        grid[x][y] = i + 1;
    }

    if (grid[1][1] == 0) {
        dp[1][1][0][0] = 1;
    } else {
        dp[1][1][1][grid[1][1]] = 1;
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            if (x == 1 && y == 1) {
                continue;
            }

            for (int cnt = 0; cnt <= c; cnt++) {
                for (int last = 0; last <= c; last++) {
                    if (grid[x][y] == 0) {
                        dp[x][y][cnt][last] = (dp[x - 1][y][cnt][last] + dp[x][y - 1][cnt][last]) % 1000007;
                    } else {
                        if (cnt > 0 && last == grid[x][y]) {
                            for (int p = 0; p < grid[x][y]; p++) {
                                dp[x][y][cnt][last] += (dp[x - 1][y][cnt - 1][p] + dp[x][y - 1][cnt - 1][p]) % 1000007;
                                dp[x][y][cnt][last] %= 1000007;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i <= c; i++) {
        int total = 0;

        for (int j = 0; j <= c; j++) {
            total += dp[n][m][i][j];
            total %= 1000007;
        }

        cout << total << " ";
    }

    cout << "\n";

    return 0;
}
