#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 100001

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<vector<int>> stickers(2, vector<int>(MAX));
        vector<vector<int>> dp(2, vector<int>(MAX));
        
        for(int i = 0; i < 2; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> stickers[i][j];
            }
        }
        
        dp[0][1] = stickers[0][1];
        dp[1][1] = stickers[1][1];
        dp[0][2] = dp[1][1] + stickers[0][2];
        dp[1][2] = dp[0][1] + stickers[1][2];
        
        for(int i = 3; i <= n; i++) {
            for(int j = 0; j < 2; j++) {
                if(j == 0) {
                    dp[j][i] = stickers[j][i] + max(dp[1][i - 1], dp[1][i - 2]);
                } else {
                    dp[j][i] = stickers[j][i] + max(dp[0][i - 1], dp[0][i - 2]);
                }
            }
        }
        
        cout << max(dp[0][n], dp[1][n]) << "\n";
    }
    
    return 0;
}
