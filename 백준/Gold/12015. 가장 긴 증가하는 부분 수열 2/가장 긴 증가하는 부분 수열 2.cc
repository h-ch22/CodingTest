#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int left, int right, int key, vector<int>& memo) {
    int mid = 0;

    while (left < right) {
        mid = (left + right) / 2;

        if (memo[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> matrix(n);
    vector<int> memo(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    int length = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        arr[i] = matrix[i];

        if (matrix[i] > memo[length]) {
            length += 1;
            memo[length] = matrix[i];
        } else {
            idx = binarySearch(0, length, arr[i], memo);
            memo[idx] = arr[i];
        }
    }

    cout << length << "\n";

    return 0;
}
