#include <iostream>
#include <vector>

using namespace std;

struct basketInfo {
    int i;
    int j;
    int k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<basketInfo> basketInfos(m);
    vector<int> baskets(n + 1);

    for (int i = 0; i < m; i++) {
        int begin, end, value;
        cin >> begin >> end >> value;

        basketInfos[i].i = begin;
        basketInfos[i].j = end;
        basketInfos[i].k = value;
    }

    for (int i = 0; i < m; i++) {
        int begin = basketInfos[i].i;
        int end = basketInfos[i].j;
        int value = basketInfos[i].k;

        for (int j = begin; j <= end; j++) {
            baskets[j] = value;
        }
    }

    for (int i = 1; i < n + 1; i++) {
        cout << baskets[i] << " ";
    }

    return 0;
}
