#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> nums(10);

    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;

        nums[i] = num % 42;
    }

    set numSet(nums.begin(), nums.end());

    cout << numSet.size() << "\n";

    return 0;
}
