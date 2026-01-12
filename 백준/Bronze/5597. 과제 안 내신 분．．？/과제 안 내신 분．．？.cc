#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> submits(31);

    for (int i = 0; i < 28; i++) {
        int idx;
        cin >> idx;

        submits[idx] = idx;
    }

    submits[0] = -1;

    const auto notSubmittedFirst = find(submits.begin(), submits.end(), 0) - submits.begin();

    cout << notSubmittedFirst << '\n';
    submits[notSubmittedFirst] = -1;

    const auto notSubmittedLast = find(submits.begin(), submits.end(), 0) - submits.begin();

    cout << notSubmittedLast;

    return 0;
}
