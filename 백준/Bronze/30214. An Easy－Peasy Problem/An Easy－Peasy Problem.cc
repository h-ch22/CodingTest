#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double s1, s2;
    cin >> s1 >> s2;

    cout << (s1 >= (s2 / 2.0) ? "E" : "H") << "\n";

    return 0;
}