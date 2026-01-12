#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> n(9);

    for (int i = 0; i < 9; i++) {
        cin >> n[i];
    }

    cout << *max_element(n.begin(), n.end()) << '\n';
    cout << distance(n.begin(), max_element(n.begin(), n.end())) + 1;

    return 0;
}
