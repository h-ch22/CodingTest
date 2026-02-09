#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int tmp) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }

    hanoi(n - 1, from, tmp, to);
    cout << from << " " << to << "\n";
    hanoi(n - 1, tmp, to, from);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << (1 << n) - 1 <<"\n";
    hanoi(n, 1, 3, 2);

    return 0;
}
