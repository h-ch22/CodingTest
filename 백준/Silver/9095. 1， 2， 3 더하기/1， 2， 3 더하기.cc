/*
 * - 1 (1)
 * 1
 *
 * - 2 (2)
 * 1 + 1
 * 2
 *
 * - 3 (4)
 * 1 + 1 + 1
 * 2 + 1
 * 1 + 2
 * 3
 *
 * - 4 (7)
 * 1 + 1 + 1 + 1
 * 1 + 1 + 2
 * 1 + 2 + 1
 * 2 + 1 + 1
 * 2 + 2
 * 1 + 3
 * 3 + 1
 *
 * - 5 (13)
 * 1 + 1 + 1 + 1 + 1
 * 1 + 1 + 1 + 2
 * 1 + 1 + 2 + 1
 * 1 + 2 + 1 + 1
 * 2 + 1 + 1 + 1
 * 1 + 2 + 2
 * 2 + 1 + 2
 * 2 + 2 + 1
 * 1 + 1 + 3
 * 1 + 3 + 1
 * 3 + 1 + 1
 * 3 + 2
 * 2 + 3
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        if (n < 2) {
            cout << 1 << "\n";
            continue;
        }

        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        cout << dp[n] << "\n";
    }

    return 0;
}
