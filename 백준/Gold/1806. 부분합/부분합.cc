#include <iostream>
#include <vector>

#define INF 10000LL * 100000000LL + 1LL

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<long long> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long start = 0;
    long long end = 0;
    long long sum = nums[0];
    long long minLength = INF;

    while (start <= end && end < n) {
        if (sum >= s) {
            minLength = min(minLength, end - start + 1LL);
            sum -= nums[start];
            start++;
        } else {
            end++;
            
            if (end < n) {
                sum += nums[end];
            }
        }
    }

    cout << (minLength == INF ? 0 : minLength) << "\n";

    return 0;
}
