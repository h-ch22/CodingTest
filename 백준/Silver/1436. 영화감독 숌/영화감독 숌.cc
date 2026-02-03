#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int num = 666;
    int count = 1;

    while (true) {
        if (count == n) {
            cout << num << "\n";
            break;
        }

        num++;

        if (to_string(num).find("666") != string::npos) {
            count++;
        }
    }

    return 0;
}
