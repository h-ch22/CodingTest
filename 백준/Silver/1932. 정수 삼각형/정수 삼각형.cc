#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<long long>> t(n);

    for (int i = 0; i < n; i++) {
        t[i] = vector<long long>(i + 1);

        for (int j = 0; j < i + 1; j++) {
            cin >> t[i][j];
        }
    }

    vector<vector<long long>> dp(n);
    dp[n - 1] = t[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        vector<long long> tmp(i + 1);

        for (int j = 0; j <= i; j++) {
            tmp[j] = (t[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]));
        }

        dp[i] = tmp;
    }

    cout << dp[0][0] << "\n";

    return 0;
}
