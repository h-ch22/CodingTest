#include <iostream>

using namespace std;

int f_n(int a_1, int n, int a_0) {
    return (a_1 * n) + a_0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a_1, a_0;
    cin >> a_1 >> a_0;

    int c;
    cin >> c;

    int n_0;
    cin >> n_0;

    bool isFail = false;

    while (true) {
        if (n_0 > 100) {
            break;
        }

        int fNResult = f_n(a_1, n_0, a_0);
        int cGN = c * n_0;

        if (fNResult > cGN) {
            isFail = true;
            break;
        }

        n_0++;
    }

    cout << (isFail ? 0 : 1) << "\n";

    return 0;
}
