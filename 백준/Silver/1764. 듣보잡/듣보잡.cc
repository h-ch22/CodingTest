#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, int> notSeenOrHeard;
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        notSeenOrHeard[name]++;
    }

    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;
        notSeenOrHeard[name]++;
    }

    vector<string> notSeenAndHeard;

    for (auto const& entry: notSeenOrHeard) {
        if (entry.second == 2) {
            notSeenAndHeard.emplace_back(entry.first);
        }
    }

    cout << notSeenAndHeard.size() << "\n";

    for (string& name: notSeenAndHeard) {
        cout << name << "\n";
    }

    return 0;
}
