#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> consults(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> consults[i].first >> consults[i].second;
    }
    
    vector<int> dp(n + 2);
    
    for(int i = n; i >= 1; i--) {
        int nextDay = i + consults[i].first;
        
        if(nextDay > n + 1) {
            dp[i] = dp[i + 1];
        } else {
            dp[i] = max(dp[i + 1], consults[i].second + dp[nextDay]);
        }
    }
    
    cout << dp[1] << "\n";
    
    return 0;
}
