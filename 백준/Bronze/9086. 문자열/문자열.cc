#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        cout << str[0] << str[str.length() - 1] << "\n";
    }

    return 0;
}
