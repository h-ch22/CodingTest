#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, string> m = {
        { "Algorithm", "204" },
        { "DataAnalysis", "207" },
        { "ArtificialIntelligence", "302" },
        { "CyberSecurity", "B101" },
        { "Network", "303" },
        { "Startup", "501" },
        { "TestStrategy", "105" }
    };

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (m.find(s) != m.end()) {
            cout << m[s] << "\n";
        } else {
            for (auto const& k: m) {
                if (k.second == s) {
                    cout << k.first << "\n";
                    break;
                }
            }
        }
    }
    
    return 0;
}
