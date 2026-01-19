#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void getPrimes(int start, int end) {
    int sum = 0;
    vector<int> primes;

    for (int i = start; i <= end; i++) {
        if (i < 2) {
            continue;
        }

        bool isPrime = true;

        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            sum += i;
            primes.push_back(i);
        }
    }

    if (primes.empty()) {
        cout << -1 << "\n";
    } else {
        cout << sum << "\n" << *min(primes.begin(), primes.end()) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    getPrimes(m, n);

    return 0;
}
