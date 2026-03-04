#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> matrix(n);
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        
        for(int j = 0; j < i; j++) {
            if(matrix[i] < matrix[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << "\n";
    
    return 0;
}
