#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        
        vector<int> dp(12);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for(int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        
        cout << dp[n] << "\n";
    }
    
    return 0;
}
