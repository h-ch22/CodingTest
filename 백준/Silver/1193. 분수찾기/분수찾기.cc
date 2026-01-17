/*
 * (n=1) -> 1/1
 * (n=2) -> 1/2
 * (n=3) -> 2/1
 * (n=4) -> 3/1
 * (n=5) -> 2/2
 * floor 1 -> 1/1
 * floor 2 -> 1/2, 2/1
 * floor 3 -> 3/1, 2/2, 1/3
 * floor 4 -> 1/4, 2/3, 3/2, 4/1
 * floor 5 -> 5/1, 4/2, 3/3, 2/4, 1/5
 * floor n (n은 짝수) -> 1/n, 2/(n-1), ..., n/1 -> n개
 * floor n (n은 홀수) -> n/1, (n-1)/2, ..., 1/n -> n개
 */

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    int floor = 1;
    int count = 1;

    int numerator = 1;
    int denominator = 1;

    while (count < x) {
        floor++;
        numerator = floor % 2 == 0 ? 1 : floor;
        denominator = floor % 2 == 0 ? floor : 1;

        if (floor % 2 == 0) {
            while (true) {
                count++;

                if (count == x || denominator == 1) {
                    break;
                }

                numerator++;
                denominator--;
            }
        } else {
            while (true) {
                count++;

                if (count == x || numerator == 1) {
                    break;
                }

                numerator--;
                denominator++;
            }
        }
    }

    cout << numerator << "/" << denominator;

    return 0;
}
