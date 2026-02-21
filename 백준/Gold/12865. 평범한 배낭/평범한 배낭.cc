#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> bag(n);

    for (int i = 0; i < n; i++) {
        cin >> bag[i].first >> bag[i].second;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= k; w++) {
            if (bag[i - 1].first <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - bag[i - 1].first] + bag[i - 1].second);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[n][k] << "\n";

    return 0;
}
