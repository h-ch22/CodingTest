#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    vector<int> stack;

    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            stack.pop_back();
        } else {
            stack.emplace_back(num);
        }
    }

    cout << accumulate(stack.begin(), stack.end(), 0) << "\n";

    return 0;
}
