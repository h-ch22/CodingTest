#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(3));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0] = matrix[0];
    
    for(int i = 1; i < n; i++) {
        dp[i][0] = matrix[i][0] + min(
            dp[i - 1][1], dp[i - 1][2]
        );
        
        dp[i][1] = matrix[i][1] + min(
            dp[i - 1][0], dp[i - 1][2]
        );
        
        dp[i][2] = matrix[i][2] + min(
            dp[i - 1][0], dp[i - 1][1]    
        );
    }
    
    int answer = *min_element(dp[n - 1].begin(), dp[n - 1].end());
    
    cout << answer << "\n";
    
    return 0;
}
