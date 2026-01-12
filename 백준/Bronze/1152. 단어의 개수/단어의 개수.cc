#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    getline(cin, str);

    int cnt = 0;
    stringstream ss(str);

    while (getline(ss, str, ' ')) {
        if (!str.empty()) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
