#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<vector<int>>>& dp, int day, int late, int absent, int n) {
    if (dp[day][late][absent] != -1) {
        return dp[day][late][absent];
    }

    if (day == n) {
        return 1;
    }

    int currentCombinations = 0;

    currentCombinations = currentCombinations % 1000000 + dfs(dp, day + 1, late, 0, n) % 1000000;

    if (late == 0) {
        currentCombinations = currentCombinations % 1000000 + dfs(dp, day + 1, 1, 0, n) % 1000000;
    }

    if (absent < 2) {
        currentCombinations = currentCombinations % 1000000 + dfs(dp, day + 1, late, absent + 1, n) % 1000000;
    }

    return dp[day][late][absent] = currentCombinations % 1000000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // dp[Day][Late][Absent]
    vector<vector<vector<int>>> dp(1001, vector<vector<int>>(2, vector<int>(3, -1)));

    int n;
    cin >> n;

    cout << dfs(dp, 0, 0, 0, n) << "\n";

    return 0;
}
