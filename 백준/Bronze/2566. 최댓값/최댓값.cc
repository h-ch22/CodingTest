#include <iostream>

using namespace std;

int main() {
    int max = -1;
    int c, r;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int temp;
            cin >> temp;

            if (max < temp) {
                max = temp;
                c = i;
                r = j;
            }
        }
    }

    cout << max << "\n";
    cout << c+1 << " " << r+1 << "\n";

    return 0;
}
