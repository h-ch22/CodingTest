#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> dp(k + 1);
    vector<int> coins(n);
    
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    dp[0] = 1;

    for(int coin: coins) {
        for(int j = 1; j <= k; j++) {
            if(j >= coin) {
                dp[j] += dp[j - coin];
            }
        }
    }
    
    cout << dp[k] << "\n";
    
    return 0;
}
