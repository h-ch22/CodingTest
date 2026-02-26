#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> dp(n + 1);
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        if(i == 2) {
            dp[i] = 2;
        } else {
            dp[i] = ((dp[i - 1] % 15746) + (dp[i - 2] % 15746)) % 15746;
        }
    }
    
    cout << dp[n] << "\n";
    
    return 0;
}
