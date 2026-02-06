#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    unordered_map<int, string> nums;

    for (int i = 0; i < a; i++) {
        int num;
        cin >> num;
        nums[num] += "A";
    }

    for (int i = 0; i < b; i++) {
        int num;
        cin >> num;
        nums[num] += "B";
    }

    int count = 0;

    for (auto const& iter: nums) {
        if (iter.second == "A" || iter.second == "B") {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
