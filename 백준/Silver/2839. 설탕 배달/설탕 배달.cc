#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int count = 0;

    while (true) {
        if (n % 5 == 0) {
            count += n / 5;
            cout << count << "\n";
            break;
        }

        if (n < 1) {
            cout << -1 << "\n";
            break;
        }

        count++;
        n -= 3;
    }

    return 0;
}
