#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> costs(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dp[i][j] = costs[i][j] + min(dp[i - 1][1], dp[i - 1][2]);
            } else if (j == 1) {
                dp[i][j] = costs[i][j] + min(dp[i - 1][0], dp[i - 1][2]);
            } else {
                dp[i][j] = costs[i][j] + min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
    }

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << "\n";

    return 0;
}
