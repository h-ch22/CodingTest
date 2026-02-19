/*
 * 1 -> (0)
 * 2 -> (1)
 * 3 -> (1)
 * 4 -> 2 -> 1 (2)
 * 5 -> 4 -> 2 -> 1 (3)
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> memo(n + 1, 0);
    memo[2] = 1;
    memo[3] = 1;

    for (int i = 4; i <= n; i++) {
        if (i % 2 != 0 && i % 3 != 0) {
            memo[i] = memo[i - 1] + 1;
        } else if (i % 2 == 0 && i % 3 == 0) {
            memo[i] = min(memo[i - 1] + 1, min(memo[i / 2] + 1, memo[i / 3] + 1));
        } else if (i % 2 == 0) {
            memo[i] = min(memo[i - 1] + 1, memo[i / 2] + 1);
        } else if (i % 3 == 0) {
            memo[i] = min(memo[i - 1] + 1, memo[i / 3] + 1);
        }
    }

    cout << memo[n] << "\n";

    return 0;
}
