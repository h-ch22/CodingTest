#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> dp(n + 1);
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        dp[i] = i;
        
        int target = 2;
        
        while(target * target <= i) {
            dp[i] = min(dp[i], dp[i - target * target] + 1);
            target++;
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
