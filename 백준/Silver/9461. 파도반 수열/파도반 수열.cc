#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<long long> dp(101);
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i = 3; i <= 100; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        
        cout << dp[n] << "\n";
    }
    
    return 0;
}
