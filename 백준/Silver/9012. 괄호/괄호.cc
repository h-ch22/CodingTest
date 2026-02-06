#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s[0] == ')' || s[s.length() - 1] == '(') {
            cout << "NO\n";
            continue;
        }

        int countOfOpenParens = 0;
        bool isFail = false;

        for (char c: s) {
            if (c == '(') {
                countOfOpenParens++;
            } else {
                if (countOfOpenParens == 0) {
                    isFail = true;
                    break;
                } else {
                    countOfOpenParens--;
                }
            }
        }

        cout << (isFail || countOfOpenParens > 0 ? "NO\n" : "YES\n");
     }

    return 0;
}
