#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (lis.empty() || lis[lis.size() - 1] < arr[i]) {
            lis.emplace_back(arr[i]);
            continue;
        }

        const int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        lis[pos] = arr[i];
    }

    cout << lis.size() << "\n";

    return 0;
}
