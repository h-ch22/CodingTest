#include <iostream>

using namespace std;

long long power(long long a, long long n, long long c) {
    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        const long long half = power(a, n / 2, c);
        return ((half % c) * (half % c)) % c;
    }

    const long long half = power(a, (n - 1) / 2, c);
    const long long tmp = ((half % c) * (half % c)) % c;

    return (tmp * (a % c)) % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;

    const long long result = power(a, b, c);

    cout << result << "\n";

    return 0;
}
