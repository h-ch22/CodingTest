#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int stairs[n];

    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
    }

    vector<int> dp(n);
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << dp[n - 1] << "\n";

    return 0;
}
