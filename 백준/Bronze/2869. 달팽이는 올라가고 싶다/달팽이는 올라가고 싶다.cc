/*
 * A: 2, B: 1, V: 5
 * -> 1일: 0m -> 2m, 2일: 1m -> 3m, 3일: 2m -> 4m, 4일: 3m -> 5m (총 4일)
 * -> 1일차: 1m (a-b m), 2일차: 2m (d1 + (a-b) m), ...
 *
 * A: 5, B: 1, V: 6
 * -> 1일: 0m -> 5m, 2일: 4m -> 9m (총 2일)
 * -> 1일차: 4m (a-b m), 2일차: 8m (d1 + (a-b) m)
 * -> a - b = 4
 */

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, v;
    cin >> a >> b >> v;

    v = v - b;

    int meterPerDay = a - b;
    int days = v / meterPerDay;

    if (v % meterPerDay == 0) {
        cout << days;
    } else {
        cout << days + 1;
    }

    return 0;
}
