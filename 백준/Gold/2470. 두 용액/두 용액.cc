#include <iostream>
#include <algorithm>
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
    int left = 0;
    int right = n - 1;
    sort(matrix.begin(), matrix.end());

    while (left < right) {
        long long sum = matrix[left] + matrix[right];

        if (abs(sum) < minSum) {
            minSum = abs(sum);
            answer[0] = matrix[left];
            answer[1] = matrix[right];
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0){
            right--;
        } else {
            break;
        }
    }

    for (int i: answer) {
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}
