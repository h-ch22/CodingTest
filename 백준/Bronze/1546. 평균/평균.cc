#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<double> scores(n);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    int maxScore = *max_element(scores.begin(), scores.end());

    for (int i = 0; i < n; i++) {
        scores[i] = scores[i] / maxScore * 100;
    }

    cout << accumulate(scores.begin(), scores.end(), 0.0) / n;

    return 0;
}
