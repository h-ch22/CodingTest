#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        for(int i = 0; i < num; i++) {
            cout << '=';
        }
        
        cout << "\n";
    }
    
    return 0;
}
