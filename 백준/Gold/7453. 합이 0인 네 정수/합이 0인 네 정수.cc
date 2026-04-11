#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    vector<int> D(n);

    vector<int> AB;
    vector<int> CD;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            switch (j) {
                case 0:
                    cin >> A[i];
                    break;

                case 1:
                    cin >> B[i];
                    break;

                case 2:
                    cin >> C[i];
                    break;

                case 3:
                    cin >> D[i];
                    break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            AB.emplace_back(A[i] + B[j]);
            CD.emplace_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    int start = 0;
    int end = CD.size() - 1;
    long long totalCount = 0;

    while (start < AB.size() && end >= 0) {
        const int sum = AB[start] + CD[end];

        if (sum >= 0) {
            if (sum == 0) {
                long long countOfA = 0;
                long long countOfB = 0;

                int currentA = AB[start];
                int currentB = CD[end];

                while (start < AB.size() && currentA == AB[start]) {
                    countOfA++;
                    start++;
                }

                while (end >= 0 && currentB == CD[end]) {
                    countOfB++;
                    end--;
                }

                totalCount += (countOfA * countOfB);
            } else {
                end--;
            }
        } else {
            start++;
        }
    }

    cout << totalCount << "\n";

    return 0;
}
