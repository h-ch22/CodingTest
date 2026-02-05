#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, bool> cards;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        cards.insert(make_pair(card, true));
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        cout << (cards.find(num) == cards.end() ? 0 : 1) << " ";
    }

    return 0;
}
