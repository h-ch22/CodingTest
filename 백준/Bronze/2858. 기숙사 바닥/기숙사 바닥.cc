#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cntR, cntB;
    cin >> cntR >> cntB;

    for (int i = 3; i < 5000; i++) {
        for (int j = 3; j < 5000; j++) {
            if ((2 * (i - 2) + (2 * (j - 2)) + 4) == cntR) {
                if (i * j == (cntR + cntB) && j >= i) {
                    cout << j << ' ' << i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
