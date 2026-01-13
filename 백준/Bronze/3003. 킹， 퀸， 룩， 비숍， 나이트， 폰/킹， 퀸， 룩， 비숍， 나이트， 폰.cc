#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector originalPieces = { 1, 1, 2, 2, 2, 8 };
    vector<int> pieces(6);

    for (int i = 0; i < 6; i++) {
        cin >> pieces[i];
    }

    for (int i = 0; i < 6; i++) {
        cout << originalPieces[i] - pieces[i] << " ";
    }

    return 0;
}
