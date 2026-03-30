#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<int> sits;
    
    int count = 0;

    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;

        if (sits.find(s) != sits.end()) {
            count++;
        } else {
            sits.emplace(s);
        }
    }
    
    cout << count << "\n";

    return 0;
}