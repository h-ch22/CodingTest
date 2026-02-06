#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> nums;

    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;

        if (command <= 2) {
            int num;
            cin >> num;

            if (command == 1) {
                nums.emplace_front(num);
            } else {
                nums.emplace_back(num);
            }
        } else if (command == 3) {
            if (!nums.empty()) {
                cout << nums.front() << "\n";
                nums.pop_front();
            } else {
                cout << -1 << "\n";
            }
        } else if (command == 4) {
            if (!nums.empty()) {
                cout << nums.back() << "\n";
                nums.pop_back();
            } else {
                cout << -1 << "\n";
            }
        } else if (command == 5) {
            cout << nums.size() << "\n";
        } else if (command == 6) {
            cout << (nums.empty() ? 1 : 0) << "\n";
        } else if (command == 7) {
            cout << (nums.empty() ? -1 : nums.front()) << "\n";
        } else if (command == 8) {
            cout << (nums.empty() ? -1 : nums.back()) << "\n";
        }
    }

    return 0;
}
