#include <iostream>
#define MAX 10000
#define MIN (-10000)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int minX = MAX;
    int maxX = MIN;
    int minY = MAX;
    int maxY = MIN;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (x < minX) {
            minX = x;
        }

        if (x > maxX) {
            maxX = x;
        }

        if (y < minY) {
            minY = y;
        }

        if (y > maxY) {
            maxY = y;
        }
    }

    int area = (maxX - minX) * (maxY - minY);

    cout << (area < 0 ? 0 : area) << "\n";

    return 0;
}
