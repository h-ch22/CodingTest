/*
 * fib(0) -> [1, 0]
 * fib(1) -> [0, 1]
 * fib(2) -> [1, 1]
 * fib(3) -> [1, 2]
 * fib(4) -> [2, 3]
 * fib(5) -> {3, 5]
 * fib(n) -> [fib(n-2).first + fib(n-1).first, fib(n-2).second + fib(n-1).second]
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
        vector<pair<int, int>> dp(n + 1);

        dp[0] = make_pair(1, 0);
        dp[1] = make_pair(0, 1);

        for (int i = 2; i <= n; i++) {
            dp[i] = make_pair(dp[i - 2].first + dp[i - 1].first, dp[i - 2].second + dp[i - 1].second);
        }

        cout << dp[n].first << " " << dp[n].second << "\n";
    }

    return 0;
}
