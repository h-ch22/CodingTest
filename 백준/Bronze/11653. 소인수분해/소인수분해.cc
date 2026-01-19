#include <iostream>

using namespace std;

void getPrimeFactors(int n) {
    int num = n;

    for (int i = 2; i * i <= n; i++) {
        while (num % i == 0) {
            num /= i;
            cout << i << "\n";
        }
    }

    if (num > 1) {
        cout << num << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n > 1) {
        getPrimeFactors(n);
    }

    return 0;
}
