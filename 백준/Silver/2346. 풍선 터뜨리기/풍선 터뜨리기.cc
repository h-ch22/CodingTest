#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

void moveNext(deque<pair<int, int>>& queue, int steps) {
    for (int i = 0; i < steps; i++) {
        queue.push_back(queue.front());
        queue.pop_front();
    }
}

void movePrev(deque<pair<int, int>>& queue, int steps) {
    for (int i = 0; i < steps; i++) {
        queue.push_front(queue.back());
        queue.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<pair<int, int>> balloons;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        balloons.push_back({i + 1, val});
    }

    while (!balloons.empty()) {
        pair<int, int> target = balloons.front();
        balloons.pop_front();
        
        cout << target.first << " ";

        if (balloons.empty()) break;

        int move = target.second;
        
        if (move > 0) {
            moveNext(balloons, move - 1);
        } else {
            movePrev(balloons, -move);
        }
    }

    return 0;
}