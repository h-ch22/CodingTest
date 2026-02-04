#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    int x, y;

    Point(int x, int y) {
        this -> x = x;
        this -> y = y;
    }

    Point() : x(0), y(0) {
    }

    bool operator <(const Point& point) const {
        return this -> x != point.x ? this -> x < point.x : this -> y < point.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Point> points(n);

    for (int i = 0; i < n; i++) {
        Point point;
        cin >> point.x >> point.y;
        points[i] = point;
    }

    sort(points.begin(), points.end());

    for (int i = 0; i < n; i++) {
        cout << points[i].x << " " << points[i].y << "\n";
    }

    return 0;
}
