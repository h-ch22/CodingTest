#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    switch(s[0]) {
        case 'F':
            cout << "Foundation";
            break;
            
        case 'C':
            cout << "Claves";
            break;
            
        case 'V':
            cout << "Veritas";
            break;
            
        case 'E':
            cout << "Exploration";
            break;
    }
    
    cout << "\n";
    
    return 0;
}
