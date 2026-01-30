#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int maxLen = max({ a, b, c });
    int anotherSides = a + b + c - maxLen;

    if (maxLen < anotherSides) {
        cout << a + b + c << "\n";
    } else {
        cout << anotherSides * 2 - 1 << "\n";
    }

    return 0;
}
