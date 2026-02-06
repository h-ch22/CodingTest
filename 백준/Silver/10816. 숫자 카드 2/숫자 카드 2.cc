#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;

    unordered_map<int, int> cards;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;

        cards[card]++;
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int card;
        cin >> card;

        cout << cards[card] << " ";
    }

    return 0;
}
