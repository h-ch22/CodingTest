#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int idx;
    cin >> idx;

    cout << str[idx - 1];

    return 0;
}
