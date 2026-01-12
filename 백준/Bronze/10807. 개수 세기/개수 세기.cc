#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int cnt = 0;
    int v;
    cin >> v;

    for (int i = 0; i < n; i++) {
        if (nums[i] == v) {
            cnt ++;
        }
    }

    cout << cnt;

    return 0;
}
