#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if(a + c == b + d) {
        cout << "Either" << "\n";
    } else {
        cout << (a + c > b + d ? "Yongdap" : "Hanyang Univ.") << "\n";
    }
    
    return 0;
}
