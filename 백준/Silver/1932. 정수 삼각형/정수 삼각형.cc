#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> triangle(n);
    
    for(int i = 1; i <= n; i++) {
        vector<int> row(i);
        
        for(int j = 0; j < i; j++) {
            cin >> row[j];
        }
        
        triangle[i - 1] = row;
    }
    
    vector<vector<int>> dp(n);
    
    dp[0] = triangle[n - 1];
    
    for(int i = 1; i < n; i++) {
        vector<int> row(n - i);
        
        for(int j = 0; j < n - i; j++) {
            row[j] = triangle[n - i - 1][j] + max(dp[i - 1][j], dp[i - 1][j + 1]);
        }
        
        dp[i] = row;
    }
    
    cout << dp[n - 1][0] << "\n";
    
    return 0;
}
