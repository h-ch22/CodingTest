#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 'a'; i <= 'z'; i++) {
        int idx = s.find(i);

        if (idx == string::npos) {
            cout << -1;
        } else {
            cout << idx;
        }

        cout << ' ';
    }

    return 0;
}
