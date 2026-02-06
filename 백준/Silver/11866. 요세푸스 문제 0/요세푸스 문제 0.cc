#include <iostream>
#include <deque>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    deque<int> nums(n);
    iota(nums.begin(), nums.end(), 1);

    cout << "<";
    int count = 0;

    while (!nums.empty()) {
        if (count < k - 1) {
            int target = nums.front();
            nums.pop_front();
            nums.emplace_back(target);
            count++;
        } else {
            cout << nums.front();
            nums.pop_front();

            if (!nums.empty()) {
                cout << ", ";
            }

            count = 0;
        }
    }

    cout << ">\n";

    return 0;
}
