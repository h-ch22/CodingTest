#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> queue;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;

            if (queue.size() < n) {
                queue.emplace(num);
            } else {
                if (queue.top() < num) {
                    queue.pop();
                    queue.emplace(num);
                }
            }
        }
    }

    cout << queue.top() << "\n";

    return 0;
}