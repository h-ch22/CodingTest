#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 100; i++) {
        string s;
        getline(cin, s);

        cout << s << "\n";
    }

    return 0;
}
