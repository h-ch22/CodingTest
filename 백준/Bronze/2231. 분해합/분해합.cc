#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string n;
    cin >> n;

    bool isFind = false;

    for (int i = 0; i <= stoi(n); i++) {
        string num = to_string(i);
        int numSum = stoi(num);

        for (char s: num) {
            numSum += s - '0';
        }

        if (numSum == stoi(n)) {
            cout << num << "\n";
            isFind = true;
            break;
        }
    }

    if (!isFind) {
        cout << 0 << "\n";
    }

    return 0;
}
