#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    cout << fibonacci(n) << "\n";
    return 0;
}
