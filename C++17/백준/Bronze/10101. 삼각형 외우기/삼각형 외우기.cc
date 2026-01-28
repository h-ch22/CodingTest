#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int angle_1, angle_2, angle_3;

    cin >> angle_1 >> angle_2 >> angle_3;

    if (angle_1 + angle_2 + angle_3 != 180) {
        cout << "Error" << "\n";
    } else if (angle_1 == 60 && angle_2 == 60 && angle_3 == 60) {
        cout << "Equilateral" << "\n";
    } else if (angle_1 == angle_2 || angle_2 == angle_3 || angle_1 == angle_3) {
        cout << "Isosceles" << "\n";
    } else {
        cout << "Scalene" << "\n";
    }

    return 0;
}
