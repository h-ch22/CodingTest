#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<pair<int, int>> dp(41);
    dp[0] = make_pair(1, 0);
    dp[1] = make_pair(0, 1);
    dp[2] = make_pair(1, 1);
    
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        
        for(int i = 3; i <= n; i++) {
            int cntOfZero = dp[i - 1].first + dp[i - 2].first;
            
            int cntOfOne = dp[i - 1].second + dp[i - 2].second;
            
            dp[i] = make_pair(cntOfZero, cntOfOne);
        }
        
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
    
    return 0;
}
