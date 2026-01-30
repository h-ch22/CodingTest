#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> cards = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1;  j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int sum = cards[i] + cards[j] + cards[k];

                if (max < sum && sum <= m) {
                    max = sum;
                }
            }
        }
    }

    cout << max << "\n";
    return 0;
}
