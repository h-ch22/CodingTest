#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        multiset<int> ms;

        int Q;
        cin >> Q;

        for (int i = 0; i < Q; i++) {
            char c;
            int num;

            cin >> c >> num;

            if (c == 'I') {
                ms.emplace(num);
            } else if (c == 'D' && !ms.empty()){
                if (num == 1) {
                    ms.erase(prev(ms.end()));
                } else {
                    ms.erase(ms.begin());
                }
            }
        }

        if (ms.empty()) {
            cout << "EMPTY" << "\n";
        } else {
            int min = *ms.begin();
            int max = *ms.rbegin();

            cout << max << " " << min << "\n";
        }
    }

    return 0;
}
