#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums(5);

    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << sum / 5 << "\n";

    sort(nums.begin(), nums.end());
    cout << nums[2] << "\n";

    return 0;
}
