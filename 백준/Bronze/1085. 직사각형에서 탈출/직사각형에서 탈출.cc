#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    pair<int, int> start = { x, y };
    pair<int, int> end = { w, h };

    int minDistance = min({ start.first, end.first - start.first, start.second, end.second - start.second });
    cout << minDistance << "\n";

    return 0;
}
