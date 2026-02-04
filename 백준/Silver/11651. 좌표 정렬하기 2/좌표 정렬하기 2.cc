#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    pair<int, int> points[n];

    for (int i = 0; i < n; i++) {
        // Swap x - y
        cin >> points[i].second >> points[i].first;
    }

    sort(points, points + n);

    for (int i = 0; i < n; i++) {
        // x - y
        cout << points[i].second << " " << points[i].first << "\n";
    }

    return 0;
}
