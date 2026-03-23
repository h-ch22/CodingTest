#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> dp(n + 1, vector<long long>(2));
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 2][j];
        }
    }

    cout << dp[n][0] + dp[n][1] << "\n";

    return 0;
}
