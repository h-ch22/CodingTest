#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool findPrime(int n) {
    bool isPrime = true;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > 1) {
            bool prime = findPrime(nums[i]);

            if (prime) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
