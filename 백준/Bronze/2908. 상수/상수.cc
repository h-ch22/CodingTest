#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << (stoi(a) > stoi(b) ? a : b);

    return 0;
}
