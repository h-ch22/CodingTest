#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string b;
    int n;

    cin >> b >> n;
    int result = 0;

    for (int i = 0; i < b.length(); i++) {
        char c = b[i];

        if (0 <= c - '0' && c - '0' <= 9) {
            result += stoi(&c) * pow(n, b.length() - 1 - i);
        } else {
            result += (c - 'A' + 10) * pow(n, b.length() - 1 - i);
        }
    }

    cout << result;

    return 0;
}
