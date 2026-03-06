#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    for(int i = 0; i < n; i++) {
        dp[i] = sequence[i];
        
        for(int j = 0; j < i; j++) {
            if(sequence[i] > sequence[j]) {
                dp[i] = max(
                    dp[i],
                    dp[j] + sequence[i]
                );
            }
        }
    }
    
    int ans = *max_element(dp.begin(), dp.end());
    cout << ans << "\n";
    
    return 0;
}
