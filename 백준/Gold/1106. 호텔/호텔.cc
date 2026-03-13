#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int c, n;
    cin >> c >> n;
    
    vector<pair<int, int>> priceAndCustomers(n);
    vector<int> dp(1101, MAX);
    
    for(int i = 0; i < n; i++) {
        cin >> priceAndCustomers[i].first >> priceAndCustomers[i].second;
    }
    
    for(int i = 0; i <= 1100; i++) {
        for(int j = 0; j < n; j++) {
            int price = priceAndCustomers[j].first;
            int customers = priceAndCustomers[j].second;
            
            dp[i] = min({
                dp[i],
                dp[i - customers] + price
            });
        }
    }
    
    int answer = *min_element(dp.begin() + c - 1, dp.end());
    cout << answer << "\n";
    
    return 0;
}
