#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> note1(n);

        for (int i = 0; i < n; i++) {
            cin >> note1[i];
        }

        int m;
        cin >> m;

        vector<int> note2(m);

        for (int i = 0; i < m; i++) {
            cin >> note2[i];
        }

        sort(note1.begin(), note1.end());

        for (int i: note2) {
            int start = 0;
            int end = n - 1;
            bool isSuccess = false;

            while (start <= end) {
                const int mid = (start + end) / 2;
                
                if (note1[mid] > i) {
                    end = mid - 1;
                } else if (note1[mid] < i) {
                    start = mid + 1;
                } else if (note1[mid] == i) {
                    cout << 1 << "\n";
                    isSuccess = true;
                    break;
                }
            }

            if (!isSuccess) {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}
