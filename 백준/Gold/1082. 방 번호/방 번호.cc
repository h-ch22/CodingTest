#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n;
    
    vector<int> prices(n);
    
    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    cin >> m;
    
    vector<string> dp(m + 1, "");

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < n; j++) {
            if(prices[j] > i) {
                continue;
            }

            string newBudget = to_string(j);
            
            if(j == 0 && dp[i] == "") {
                dp[i] = "0";
                continue;
            }
            
            int countOfZero = (i - prices[j]) / prices[0];
            
            if(dp[i - prices[j]].size() < countOfZero) {
                for(int k = 0; k < countOfZero; k++) {
                    newBudget += "0";
                }
            } else {
                newBudget += dp[i - prices[j]];
            }
            
            if(dp[i].size() < newBudget.size() || (dp[i].size() == newBudget.size() && dp[i] < newBudget)) {
                dp[i] = newBudget;
            }
        }
    }
    
    cout << dp[m] << "\n";
    
    return 0;
}
