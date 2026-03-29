#include <iostream>
#include <string>
#include <vector>

#define MAX 1000000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] > MAX ? MAX : dp[i - 1][j] + dp[i][j - 1];
        }
    }

    if (k > dp[n][m]) {
        cout << -1 << "\n";
        return 0;
    }

    string answer;

    while (n > 0 || m > 0) {
        if (n == 0) {
            answer += 'z';
            m--;
        } else if (m == 0) {
            answer += 'a';
            n--;
        } else if (k <= dp[n - 1][m]) {
            answer += 'a';
            n--;
        } else {
            answer += 'z';
            k -= dp[n - 1][m];
            m--;
        }
    }

    cout << answer << "\n";

    return 0;
}
