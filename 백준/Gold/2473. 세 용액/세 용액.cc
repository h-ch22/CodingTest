#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> liquors(n);

    for (int i = 0; i < n; i++) {
        cin >> liquors[i];
    }

    sort(liquors.begin(), liquors.end());

    long long minSum = 1000000000 * 3LL;

    vector<long long> targets(3);

    for (int i = 0; i < n; i++) {
        int start = 0;
        int end = n - 1;

        while (start < end) {
            if (start == i) {
                start++;
                continue;
            }

            if (end == i) {
                end--;
                continue;
            }

            const long long target = liquors[i];
            const long long current = liquors[start] + liquors[end] + target;

            if (abs(current) < minSum) {
                minSum = abs(current);

                targets[0] = target;
                targets[1] = liquors[start];
                targets[2] = liquors[end];
            }

            if (current == 0) {
                break;
            }

            if (current <= 0) {
                start++;
            } else {
                end--;
            }
        }
    }

    sort(targets.begin(), targets.end());

    for (const long long t: targets) {
        cout << t << " ";
    }

    cout << "\n";

    return 0;
}
