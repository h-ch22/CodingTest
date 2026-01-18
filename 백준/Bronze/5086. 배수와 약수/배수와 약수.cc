#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;

    while (true) {
        cin >> a >> b;
        
        if (a == 0 && b == 0) {
            break;
        }
        
        bool isFactor = false;
        bool isMultiple = false;

        if (a % b == 0) {
            isMultiple = true;
        }

        if (b % a == 0) {
            isFactor = true;
        }

        if (isFactor && isMultiple) {
            cout << "factor" << "\n";
        } else if (!isFactor && !isMultiple) {
            cout << "neither" << "\n";
        } else {
            cout << (isFactor ? "factor" : "multiple") << "\n";
        }
    }

    return 0;
}
