#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> baskets(n+1);

    for (int i = 1; i < n + 1; i++) {
        baskets[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int begin, end;
        cin >> begin >> end;

        reverse(baskets.begin() + begin, baskets.begin() + end + 1);
    }

    for (int i = 1; i < n + 1; i++) {
        cout << baskets[i] << " ";
    }

    return 0;
}
