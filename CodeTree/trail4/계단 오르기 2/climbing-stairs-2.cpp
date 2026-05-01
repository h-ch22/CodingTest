#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int coin[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(4));
    dp[1][1] = coin[1];
    dp[2][0] = coin[2];
    dp[2][2] = coin[1] + coin[2];

    for(int i = 3; i <= n; i++) {
        for(int j = 0; j < 4; j++) {
            if(dp[i - 2][j] != 0) {
                dp[i][j] = max(dp[i][j], dp[i - 2][j] + coin[i]);
            }

            if(j && dp[i - 1][j - 1] != 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + coin[i]);
            }
        }
    }

    int max_elem = 0;

    for(int i = 0; i < 4; i++) {
        max_elem = max(max_elem, dp[n][i]);
    }

    cout << max_elem << "\n";

    return 0;
}
