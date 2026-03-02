#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> dp(10001);
    vector<int> liquors(10001);
    
    for(int i = 1; i <= n; i++) {
        cin >> liquors[i];
    }
    
    dp[1] = liquors[1];
    dp[2] = liquors[1] + liquors[2];
    
    for(int i = 3; i <= n; i++) {
        dp[i] = max({
            dp[i - 1],
            dp[i - 3] + liquors[i - 1] + liquors[i],
            dp[i - 2] + liquors[i]
        });
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
