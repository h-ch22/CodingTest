#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define DIVISOR 1000000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(10));
    fill(dp[1].begin() + 1, dp[1].end(), 1LL);
    
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] % DIVISOR;
        dp[i][9] = dp[i - 1][8] % DIVISOR;
        
        for(int j = 1; j <= 8; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % DIVISOR;
        }
    }
    
    long long result = 0;
    
    for(int i = 0; i < 10; i++) {
        result = (result + dp[n][i]) % DIVISOR;
    }
    
    cout << result << "\n";
    
    return 0;
}
