#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (minHeap.size() < maxHeap.size()) {
            minHeap.emplace(num);
        } else {
            maxHeap.emplace(num);
        }

        if (!maxHeap.empty() && !minHeap.empty()) {
            if (maxHeap.top() > minHeap.top()) {
                int numToMax = minHeap.top();
                int numToMin = maxHeap.top();

                maxHeap.pop();
                minHeap.pop();

                maxHeap.emplace(numToMax);
                minHeap.emplace(numToMin);
            }
        }

        cout << maxHeap.top() << "\n";
    }

    return 0;
}
