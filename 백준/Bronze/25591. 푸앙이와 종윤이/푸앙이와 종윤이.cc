#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a = 100 - n;
    int b = 100 - m;
    int c = 100 - (a + b);
    int d = a * b;
    int q = 0;
    int r = d;

    if (d > 99) {
        q = d / 100;
        r = d % 100;
    }

    cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << "\n";
    cout << c + q << " " << r << "\n";

    return 0;
}
