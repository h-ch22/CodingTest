#include <iostream>
#include <algorithm>
#include <vector>

#define MIN -10000

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> dp(n, MIN);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    dp[0] = nums[0];

    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    }

    int me = *max_element(dp.begin(), dp.end());

    cout << me << "\n";

    return 0;
}