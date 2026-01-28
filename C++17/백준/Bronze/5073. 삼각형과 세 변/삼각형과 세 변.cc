#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        if (a == b && b == c && a == c) {
            cout << "Equilateral" << "\n";
            continue;
        }

        int maxSide = max({a, b, c});

        if (a + b + c - maxSide <= maxSide) {
            cout << "Invalid" << "\n";
        } else if (a == b || b == c || a == c) {
            cout << "Isosceles" << "\n";
        } else {
            cout << "Scalene" << "\n";
        }
    }

    return 0;
}
