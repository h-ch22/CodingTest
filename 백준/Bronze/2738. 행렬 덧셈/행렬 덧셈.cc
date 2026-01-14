#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    cin.ignore();

    vector<vector<int>> v1(n, vector<int>(m));
    vector<vector<int>> v2(n, vector<int>(m));

    for (int i = 0; i < n*2; i++) {
        string row;
        getline(cin, row);

        istringstream iss(row);
        string buffer;

        vector<int> result;

        while (getline(iss, buffer, ' ')) {
            result.emplace_back(stoi(buffer));
        }

        if (i >= n) {
            v2[i - n] = result;
        } else {
            v1[i] = result;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v1[i][j] + v2[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}