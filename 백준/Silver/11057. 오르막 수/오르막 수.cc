#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#define DIVISOR 10007LL

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(10LL));
    fill(dp[1].begin(), dp[1].end(), 1LL);
    
    for(int i = 2; i <= n; i++) {
        dp[i][0] = 1LL;
        
        for(int j = 1; j < 10; j++) {
            dp[i][j] = dp[i - 1][j] % DIVISOR + dp[i][j - 1] % DIVISOR;
        }
    }
    
    long long sum = 0;
    
    for(int i = 0; i < 10; i++) {
        sum = (sum + dp[n][i]) % DIVISOR;
    }
    
    cout << sum << "\n";
    
    return 0;
}
