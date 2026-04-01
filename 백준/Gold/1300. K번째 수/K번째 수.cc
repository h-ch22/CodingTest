#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long left = 1;
    long long right = k;
    long long answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int i = 1; i <= n; i++) {
            count += min(static_cast<long long>(n), mid / i);
        }

        if (count >= k) {
            right = mid - 1;
            answer = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";

    return 0;
}
