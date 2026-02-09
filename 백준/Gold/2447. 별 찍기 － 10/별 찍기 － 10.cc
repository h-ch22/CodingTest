#include <iostream>
#include <string>

using namespace std;

void printStar(int i, int j, int n) {
    if (i % 3 == 1 && j % 3 == 1) {
        cout << " ";
    } else {
        if (i == 0 && j == 0) {
            cout << "*";
        } else {
            printStar(i / 3, j / 3, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printStar(i, j, n);
        }

        cout << "\n";
    }

    return 0;
}
