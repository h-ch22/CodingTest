#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    sort(grid.begin(), grid.end());

    int x;
    cin >> x;

    int start = 0;
    int end = n - 1;
    int count = 0;

    while (start < end) {
        int sum = grid[start] + grid[end];

        if (sum == x) {
            count++;
            start++;
            end--;
        } else if (sum < x) {
            start++;
        } else if (sum > x) {
            end--;
        }
    }

    cout << count << "\n";

    return 0;
}
