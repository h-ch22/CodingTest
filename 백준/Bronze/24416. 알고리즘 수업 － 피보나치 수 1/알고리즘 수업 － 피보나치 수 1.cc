#include <iostream>
#include <vector>

using namespace std;

int fib(int n, int& count) {
    if (n == 1 || n == 2) {
        return 1;
    }

    count++;

    return fib(n - 1, count) + fib(n - 2, count);
}

void fibonacci(int n, int& count) {
    vector<int> v(n);
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;

    for (int i = 3; i < n; i++) {
        count++;
        v[i] = v[i - 1] + v[i - 2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int count = 0;
    int _ = fib(n, count);
    cout << count + 1 << " ";

    count = 0;
    fibonacci(n, count);
    cout << count + 1 << "\n";

    return 0;
}
