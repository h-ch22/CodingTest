#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> v(5);

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < v[j].length()) {
                cout << v[j][i];
            }
        }
    }

    return 0;
}
