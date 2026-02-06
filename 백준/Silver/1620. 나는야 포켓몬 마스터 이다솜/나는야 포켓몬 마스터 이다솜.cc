#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> pocketMonNames(n);
    unordered_map<string, int> pocketMonIndices;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        pocketMonIndices[name] = i + 1;
        pocketMonNames[i] = name;
    }

    for (int i = 0; i < m; i++) {
        string input;
        cin >> input;

        int idx;

        if (static_cast<int>(input[0]) < 65) {
            idx = stoi(input);
            cout << pocketMonNames[idx - 1] << "\n";
        } else {
            cout << pocketMonIndices[input] << "\n";
        }
    }

    return 0;
}
