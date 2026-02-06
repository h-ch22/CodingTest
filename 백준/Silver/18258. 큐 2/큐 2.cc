#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> queue;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int value;
            cin >> value;

            queue.emplace_back(value);
            continue;
        }

        if (command == "front") {
            cout << (queue.empty() ? -1 : queue.front()) << "\n";
        } else if (command == "pop") {
            if (queue.empty()) {
                cout << -1 << "\n";
            } else {
                cout << queue.front() << "\n";
                queue.pop_front();
            }
        } else if (command == "size") {
            cout << queue.size() << "\n";
        } else if (command == "empty") {
            cout << (queue.empty() ? 1 : 0) << "\n";
        } else if (command == "back") {
            cout << (queue.empty() ? -1 : queue.back()) << "\n";
        }
    }

    return 0;
}
