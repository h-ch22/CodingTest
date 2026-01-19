#include <iostream>
#include <cmath>

using namespace std;

int getPrime(int n, int k) {
    int cnt = 1;
    int prime = 1;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            cnt++;

            if (cnt == k) {
                prime = i;
                break;
            }
        }
    }

    if (cnt < k) {
        prime = 0;
    }

    return prime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    cout << getPrime(n, k);

    return 0;
}
