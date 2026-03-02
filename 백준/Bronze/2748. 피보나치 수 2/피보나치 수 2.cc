#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<long long> fibonacci(n + 1);
    fibonacci[1] = 1;
    
    for(int i = 2; i <= n; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    
    cout << fibonacci[n] << "\n";
    
    return 0;
}
