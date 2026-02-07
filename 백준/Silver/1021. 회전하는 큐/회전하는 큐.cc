/*
 * 1 2 3 4 5 6 7 8 9 10
 * 1 2 3
 * -> pop_first() -> 1
 * 2 3 4 5 6 7 8 9 10
 * -> pop_first() -> 2
 * 3 4 5 6 7 8 9 10
 * -> pop_first() -> 3
 * -> count: 0
 *
 * 1 2 3 4 5 6 7 8 9 10
 * 2 9 5
 * -> 1번 회전 -> pop_first() -> 2
 * 3 4 5 6 7 8 9 10 1
 * -> 3번 회전 -> pop_first() -> 9
 * 10 1 3 4 5 6 7 8
 * -> 4번 회전 -> pop_first() -> 5
 * -> count: 8
 *
 * 1. queue()의 first()를 본다 -> target이면 pop_first()
 * 2. target이 아니면 left_rotation / right_rotation 중 더 작은 것을 수행해야한다.
 */

#include <iostream>
#include <numeric>
#include <deque>

using namespace std;

int rotateLeft(deque<int>& queue, int target) {
    int count = 0;

    while (queue.front() != target) {
        int front = queue.front();
        queue.pop_front();
        queue.emplace_back(front);
        count++;
    }

    queue.pop_front();

    return count;
}

int rotateRight(deque<int>& queue, int target) {
    int count = 0;

    while (queue.front() != target) {
        int back = queue.back();
        queue.pop_back();
        queue.emplace_front(back);
        count++;
    }

    queue.pop_front();

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> queue(n);
    iota(queue.begin(), queue.end(), 1);
    int count = 0;

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        if (queue.front() == t) {
            queue.pop_front();
            continue;
        }

        deque<int> tmp = queue;
        int leftCount = rotateLeft(tmp, t);

        deque<int> tmp2 = queue;
        int rightCount = rotateRight(tmp2, t);

        if (leftCount < rightCount) {
            count += leftCount;
            queue = tmp;
        } else {
            count += rightCount;
            queue = tmp2;
        }
    }

    cout << count << "\n";

    return 0;
}
