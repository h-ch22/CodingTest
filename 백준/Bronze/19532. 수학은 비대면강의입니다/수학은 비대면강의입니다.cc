#include <iostream>

using namespace std;

bool isFind = false;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    for (int i = -999; i < 1000; i++) {
        if (isFind) break;

        for (int j = -999; j < 1000; j++) {
            if (a * i + b * j == c && d * i + e * j == f) {
                isFind = true;
                cout << i << " " << j << "\n";
                break;
            }
        }
    }

    return 0;
}
