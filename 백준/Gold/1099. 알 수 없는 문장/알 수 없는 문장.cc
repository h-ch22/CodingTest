#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int n;
    cin >> n;
    
    vector<string> words(n);
    vector<int> dp(51, 100);
    dp[0] = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    for(int i = 1; i <= s.size(); i++) {
        for(const string& w: words) {
            int l = w.size();
            
            if(i - l < 0 || dp[i - l] == 100) {
                continue;
            }
            
            const string subStr = s.substr(i - l, l);
            string sortedSub = subStr;
            string sortedW = w;
            
            sort(sortedSub.begin(), sortedSub.end());
            sort(sortedW.begin(), sortedW.end());
            
            if(sortedSub != sortedW) {
                continue;
            }
            
            int count = 0;
            
            for(int j = 0; j < subStr.size(); j++) {
                if(subStr[j] != w[j]) {
                    count++;
                }
            }
            
            dp[i] = min(dp[i], dp[i - l] + count);
        }
    }
    
    cout << (dp[s.size()] == 100 ? -1 : dp[s.size()]) << "\n";
    
    return 0;
}
