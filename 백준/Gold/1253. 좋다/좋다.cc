#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int count = 0;

    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = n - 1;
        long long target = nums[i];

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }

            if (right == i) {
                right--;
                continue;
            }

            if (target == nums[left] + nums[right]) {
                count++;
                break;
            }

            if (target < nums[left] + nums[right]) {
                right--;
            } else {
                left++;
            }
        }
    }

    cout << count << "\n";

    return 0;
}
