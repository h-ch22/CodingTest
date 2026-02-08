#include <iostream>
#include <string>

using namespace std;

void contour(string& s, int index, int length) {
    if (length == 1) {
        return;
    }

    int dividedLength = length / 3;

    for (int i = index + dividedLength; i < index + 2 * dividedLength; i++) {
        s[i] = ' ';
    }

    contour(s, index, dividedLength);
    contour(s, index + 2 * dividedLength, dividedLength);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    while (cin >> n) {
        int length = 1;

        for (int i = 1; i <= n; i++) {
            length *= 3;
        }

        string s = "";

        for (int i = 0; i < length; i++) {
            s += '-';
        }

        contour(s, 0, s.length());
        cout << s << "\n";
    }

    return 0;
}
