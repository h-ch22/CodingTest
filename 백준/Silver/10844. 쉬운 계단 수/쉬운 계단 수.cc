#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    long long p = 1000000000;

    vector<vector<long long>> dp(n + 1, vector<long long>(10));
    
    for(int i = 1; i < 10; i++) {
        dp[1][i] = static_cast<long long>(1);
    }
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0 || j == 9) {
                dp[i][j] = dp[i - 1][j == 0 ? 1 : 8] % p;
            } else {
                dp[i][j] = ((dp[i - 1][j - 1] % p) + (dp[i - 1][j + 1] % p)) % p;
            }
        }
    }
    
    int sum = 0;
    
    for(int i = 0; i < 10; i++) {
        sum = ((sum % p) + (dp[n][i] % p)) % p;
    }
    
    cout << sum << "\n";

    return 0;
}
