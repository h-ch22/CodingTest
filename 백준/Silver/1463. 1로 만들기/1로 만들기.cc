#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> dp(MAX);
    dp[2] = 1;
    dp[3] = 1;
    
    for(int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        
        if(i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        
        if(i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
