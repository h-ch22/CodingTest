#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> dp(1001);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
    }

    cout << (dp[n] % 2 == 0 ? "CY" : "SK") << "\n";
    
    return 0;
}
