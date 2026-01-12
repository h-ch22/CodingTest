#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        vector<string> v;

        while (getline(iss, s, ' ')) {
            v.push_back(s);
        }

        int r = stoi(v[0]);

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < r; j++) {
                cout << s[i];
            }
        }

        cout << '\n';
    }

    return 0;
}
