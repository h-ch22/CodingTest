#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string r;

    for (int i = 0; i < n; i++) {
        r += 'a';
    }

    cout << r << "\n";

    return 0;
}