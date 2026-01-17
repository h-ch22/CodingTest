/*
 * 1층: 1 --> 1
 * 2층: 6 (+6) --> 2~7
 * 3층: 12 (+6) --> 8~19
 * 4층: 18 (+6) --> 20~37
 */

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 1;
    } else {
        int maxRange = 1;
        int floor = 1;

        while (maxRange < n) {
            maxRange += floor * 6;
            floor++;
        }

        cout << floor;
    }

    return 0;
}
