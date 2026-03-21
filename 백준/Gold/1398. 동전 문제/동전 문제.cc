#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    
    vector<int> dp(100, 100);
    
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i < 100; i++) {
        if(i < 10) {
            dp[i] = dp[i - 1] + 1;
        }
        
        if(i >= 10) {
            dp[i] = min(dp[i], dp[i - 10] + 1);
        }
        
        if(i >= 25) {
            dp[i] = min(dp[i], dp[i - 25] + 1);
        }
    }
    
    while(T--) {
        long long price;
        cin >> price;
    
        long long totalCoins = 0;
        
        while(price > 0) {
            totalCoins += dp[price % 100];
            price /= 100;
        }
        
        cout << totalCoins << "\n";
    }
    
    return 0;
}
