#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> queueA;
    deque<int> queueB;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        queueA.emplace_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (queueA[i] == 0) {
            queueB.emplace_back(x);
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        queueB.emplace_front(x);
        cout << queueB.back() << " ";
        queueB.pop_back();
    }

    return 0;
}
