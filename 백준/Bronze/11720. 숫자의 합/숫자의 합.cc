#include <iostream>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sum = 0;
    string str;
    cin >> str;

    for (char c: str) {
        sum += static_cast<int>(c - '0');
    }

    cout << sum;

    return 0;
}
