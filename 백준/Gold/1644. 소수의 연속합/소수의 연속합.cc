#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int k = i * i; k <= n; k += i) {
                isPrime[k] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.emplace_back(i);
        }
    }

    int count = 0;
    int start = 0;
    int end = 0;
    int sum = 0;

    while (true) {
        if (sum == n) {
            count++;
            sum -= primes[start];
            start++;
        } else if (sum > n) {
            sum -= primes[start];
            start++;
        } else if (end == primes.size()) {
            break;
        } else  {
            sum += primes[end];
            end++;
        }
    }

    cout << count << "\n";

    return 0;
}
