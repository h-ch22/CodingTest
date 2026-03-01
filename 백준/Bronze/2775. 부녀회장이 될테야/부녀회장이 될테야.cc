#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int n, k;
        cin >> n >> k;
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        
        for(int i = 1; i <= k; i++) {
            dp[0][i] = i;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                dp[i][j] = accumulate(dp[i - 1].begin(), dp[i - 1].begin() + j + 1, 0);
            }
        }
        
        
        cout << dp[n][k] << "\n";
    }
    
    return 0;
}
