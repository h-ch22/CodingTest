#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, b;
    cin >> n >> b;

    string result = "";

    while (n > 0) {
        int remain = n % b;

        if (remain >= 10) {
            result += remain - 10 + 'A';
        } else {
            result += to_string(remain);
        }

        n /= b;
    }

    reverse(result.begin(), result.end());
    cout << result;

    return 0;
}
