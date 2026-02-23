#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> liquors(n);
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++) {
        cin >> liquors[i];
    }
    
    dp[0] = liquors[0];
    
    for(int i = 1; i < n; i++) {
        if(i > 2) {
            dp[i] = max(dp[i - 1], max(dp[i - 2] + liquors[i], dp[i - 3] + liquors[i - 1] + liquors[i]));
        } else if(i == 2) {
            dp[i] = max(dp[i - 1], max(dp[i - 2] + liquors[i], liquors[i - 1] + liquors[i]));
        } else {
            dp[i] = dp[i - 1] + liquors[i];
        }
    }
    
    cout << dp[n - 1] << "\n";
    
    return 0;
}