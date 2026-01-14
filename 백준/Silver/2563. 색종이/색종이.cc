#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> papers(101, vector<int>(101));

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                papers[j][k] = 1;
            }
        }
    }

    int totalSize = 0;

    for (int i = 1; i <= 100; i++) {
        totalSize += accumulate(papers[i].begin(), papers[i].end(), 0);
    }

    cout << totalSize;

    return 0;
}
