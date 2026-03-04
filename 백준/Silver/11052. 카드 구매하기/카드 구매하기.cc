#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> cards(n + 1);
    vector<int> dp(n + 1);
    
    for(int i = 1; i <= n; i++) {
        cin >> cards[i];
    }
    
    dp[1] = cards[1];
    
    for(int i = 2; i <= n; i++) {
        dp[i] = cards[i];
        
        for(int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] * (i / j) + dp[i % j]);
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
