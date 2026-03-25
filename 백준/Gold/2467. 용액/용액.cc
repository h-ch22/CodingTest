#include <iostream>
#include <vector>
#define MAX 3000000000LL

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> matrix(n);
    vector<int> answer(2);

    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }

    long long minSum = MAX;

    for (int i = 0; i < n - 1; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            long long sum = matrix[i] + matrix[mid];

            if (abs(sum) < minSum) {
                minSum = abs(sum);
                answer[0] = matrix[i];
                answer[1] = matrix[mid];
            }

            if (sum < 0) {
                left = mid + 1;
            } else if (sum > 0) {
                right = mid - 1;
            } else {
                break;
            }
        }
    }

    for (int i: answer) {
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}
