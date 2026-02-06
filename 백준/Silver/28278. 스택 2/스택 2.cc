#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> stack;

    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;

        switch (command) {
            case 1:
                int x;
                cin >> x;
                stack.emplace_back(x);
                break;

            case 2:
                if (!stack.empty()) {
                    cout << stack.back() << "\n";
                    stack.pop_back();
                } else {
                    cout << -1 << "\n";
                }
                break;

            case 3:
                cout << stack.size() << "\n";
                break;

            case 4:
                cout << (stack.empty() ? 1 : 0) << "\n";
                break;

            case 5:
                cout << (stack.empty() ? -1 : stack[stack.size() - 1]) << "\n";
                break;
        }
    }

    return 0;
}
