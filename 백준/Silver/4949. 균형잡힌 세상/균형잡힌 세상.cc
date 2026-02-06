#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string s;
        getline(cin, s);

        if (s == ".") {
            break;
        }

        vector<char> stack;
        bool isFail = false;

        for (char c: s) {
            if (c == '(' || c == '[') {
                stack.emplace_back(c);
            } else if (c == ')' || c == ']') {
                if (stack.empty()) {
                    cout << "no\n";
                    isFail = true;
                    break;
                }

                if (stack.back() == '(' && c == ']' || stack.back() == '[' && c == ')') {
                    cout << "no\n";
                    isFail = true;
                    break;
                } else {
                    stack.pop_back();
                }
            }
        }

        if (!isFail) {
            cout << (stack.empty() ? "yes\n" : "no\n");
        }
        stack.clear();
    }

    return 0;
}
