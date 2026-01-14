#include <iostream>

using namespace std;

/*
 * 0 -> 4 ( 2 x 2 )
 * 1 -> 9 ( 3 x 3 ) -> + 1 ( 2 ^ 0 )
 * 2 -> 25 ( 5 x 5 ) -> + 2 ( 2 ^ 1 )
 * 3 -> 81 ( 9 x 9 ) -> + 4 ( 2 ^ 2 )
 * 4 -> 289 ( 17 x 17 ) -> + 8 ( 2 ^ 3 )
 * 5 -> 1089 ( 33 x 33 ) -> + 16 ( 2 ^ 4 )
 */

int getRowCount(int exp) {
    int num = 1;
    int row = 3;

    for (int i = 1; i < exp; i++) {
        num *= 2;
        row += num;
    }

    return row;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int row = getRowCount(n);

    cout << row * row;

    return 0;
}
