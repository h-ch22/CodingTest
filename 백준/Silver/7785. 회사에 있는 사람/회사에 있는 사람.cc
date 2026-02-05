#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<string, bool, greater<string>> members;

    for (int i = 0; i < n; i++) {
        string name, status;
        cin >> name >> status;

        if (members.count(name)) {
            members[name] = status == "enter";
        } else {
            members.insert({name, status == "enter"});
        }
    }

    for (const auto& member: members) {
        if (member.second) {
            cout << member.first << "\n";
        }
    }

    return 0;
}
