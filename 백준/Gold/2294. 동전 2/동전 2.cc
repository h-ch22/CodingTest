#include <iostream>
#include <vector>

#define MAX 1000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> dp(k + 1, MAX);
    vector<int> coins(n);
    
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    dp[0] = 0;
    
    for(int coin: coins) {
        for(int i = coin; i <= k; i++) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    
    cout << (dp[k] == MAX ? -1 : dp[k]) << "\n";
    
    return 0;
}
