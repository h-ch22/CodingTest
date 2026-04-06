#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

deque<int> stringToQueue(string& arr) {
    deque<int> queue;
    string newArr = arr.substr(1, arr.length() - 2);
    stringstream ss(newArr);
    string token;

    while (getline(ss, token, ',')) {
        queue.emplace_back(stoi(token));
    }

    return queue;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> queue;

        if (arr != "[]") {
            queue = stringToQueue(arr);
        }

        bool isError = false;
        bool isReverse = false;

        for (char c: p) {
            if (c == 'R') {
                isReverse = !isReverse;
            } else if (c == 'D') {
                if (queue.empty()) {
                    cout << "error" << "\n";
                    isError = true;
                    break;
                }

                if (isReverse) {
                    queue.pop_back();
                } else {
                    queue.pop_front();
                }
            }
        }

        if (!isError) {
            cout << "[";

            while (!queue.empty()) {
                if (isReverse) {
                    cout << queue.back();
                } else {
                    cout << queue.front();
                }

                if (queue.size() > 1) {
                    cout << ",";
                }

                if (isReverse) {
                    queue.pop_back();
                } else {
                    queue.pop_front();
                }
            }

            cout << "]\n";
        }
    }

    return 0;
}
