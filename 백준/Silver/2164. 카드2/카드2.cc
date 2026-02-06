#include <iostream>
#include <deque>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> queue(n);
    iota(queue.begin(), queue.end(), 1);

    int i = 0;

    while (queue.size() > 1) {
        int target = queue.front();
        queue.pop_front();

        if (i % 2 != 0) {
            queue.emplace_back(target);
        }

        i++;
    }

    cout << queue.front() << "\n";

    return 0;
}
