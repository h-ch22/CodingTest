#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int>> dp(31, vector<int>(31));
    
    for(int i = 1; i < 31; i++) {
        dp[1][i] = i;
    }
    
    for(int i = 2; i < 31; i++) {
        for(int j = 1; j < 31; j++) {
            dp[i][j] = accumulate(dp[i - 1].begin(), dp[i - 1].begin() + j, 0);
        }
    }
    
    int T;
    cin >> T;
    
    while(T--) {
        int n, m;
        cin >> n >> m;
        
        cout << dp[n][m] << "\n";
    }
    
    return 0;
}
