#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int y;
        cin >> y;

        if ((y + 1) % (y % 100) == 0) {
            cout << "Good" << "\n";
        } else {
            cout << "Bye" << "\n";
        }
    }

    return 0;
}
