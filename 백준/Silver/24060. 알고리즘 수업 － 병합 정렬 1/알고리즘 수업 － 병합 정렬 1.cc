#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> arr;
vector<int> tmp;

void merge(int p, int q, int r, int k, int& count) {
    if (count < k) {
        int i = p;
        int j = q + 1;
        int t = 1;

        while (i <= q && j <= r) {
            if (arr[i] <= arr[j]) {
                tmp[t++] = arr[i++];
            } else {
                tmp[t++] = arr[j++];
            }
        }

        while (i <= q) {
            tmp[t++] = arr[i++];
        }

        while (j <= r) {
            tmp[t++] = arr[j++];
        }

        i = p;
        t = 1;

        while (i <= r) {
            count++;
            arr[i++] = tmp[t++];

            if (k == count) {
                cout << arr[i-1] << "\n";
                break;
            }
        }
    }
}

void mergeSort(int p, int r, int k, int& count) {
    if (p < r && count < k) {
        int q = ceil((p + r) / 2);
        mergeSort(p, q, k, count);
        mergeSort(q + 1, r, k, count);
        merge(p, q, r, k, count);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    arr.resize(n);
    tmp.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    mergeSort(0, n - 1, k, count);

    if (count < k) {
        cout << -1 << "\n";
    }

    return 0;
}
