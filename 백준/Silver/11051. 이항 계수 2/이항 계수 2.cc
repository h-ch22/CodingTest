#include <iostream>
#include <vector>

#define DIVISOR 10007

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> dp(1001, vector<int>(1001, 1));
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == i) {
                continue;
            }

            if(j == i - 1 || j == 1) {
                dp[i][j] = i;
            } else {
                dp[i][j] = (dp[i - 1][j - 1] % DIVISOR + dp[i - 1][j] % DIVISOR) % DIVISOR;
            }
        }
    }
    
    cout << dp[n][k] << "\n";
    
    return 0;
}
