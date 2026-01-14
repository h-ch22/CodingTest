#include <iostream>

using namespace std;

void print(int c) {
    cout << c << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    int units[3] = { 25, 10, 5 };

    for (int i = 0; i < t; i++) {
        int c;
        cin >> c;

        for (int u: units) {
            int remain = c / u;
            print(remain);
            c -= u * remain;
        }

        print(c);
    }
}
