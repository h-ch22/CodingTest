#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> seq(n);
    vector<int> lis(n);
    vector<int> dis(n);
    vector<int> dp(n);
    
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    
    for(int i = 0; i < n; i++) {
        lis[i] = 1;
        dis[n - i - 1] = 1;
        
        for(int j = 0; j < i; j++) {
            if(seq[i] > seq[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
            
            if(seq[n - i - 1] > seq[n - j - 1]) {
                dis[n - i - 1] = max(dis[n - i - 1], dis[n - j - 1] + 1);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        dp[i] = lis[i] + dis[i] - 1;
    }
    
    int ans = *max_element(dp.begin(), dp.end());
    
    cout << ans << "\n";
    
    return 0;
}
