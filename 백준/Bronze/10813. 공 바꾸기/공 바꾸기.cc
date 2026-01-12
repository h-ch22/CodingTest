#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> baskets(n+1);

    for (int i = 0; i < m; i++) {
        int begin, end;
        cin >> begin >> end;

        int originalBegin = baskets[begin];
        int originalEnd = baskets[end];

        if (originalBegin == 0) {
            originalBegin = begin;
        }

        if (originalEnd == 0) {
            originalEnd = end;
        }

        baskets[begin] = originalEnd;
        baskets[end] = originalBegin;
    }

    for (int i = 1; i < n+1; i++) {
        cout << (baskets[i] == 0 ? i : baskets[i]) << " ";
    }
}
