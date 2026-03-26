#include <iostream>

#define INF 10000000000

using namespace std;

long long binarySearch(long long from, long long start, long long end, long long x, long long y) {
    long long minCount = INF;
    long long left = start;
    long long right = end;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long newX = mid + x;
        long long newY = mid + y;
        long long newZ = newY * 100 / newX;

        if (newZ != from) {
            minCount = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return minCount == INF ? -1 : minCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y;
    cin >> x >> y;

    long long z = y * 100 / x;

    cout << binarySearch(z, 1LL, INF, x, y) << "\n";

    return 0;
}
