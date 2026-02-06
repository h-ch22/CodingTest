/*
 * 1. 번호를 N개 받아 Deque에 넣는다.
 * 2. Deque에서 pop_front()한다.
 * 3-1. Stack이 비어있거나, Stack의 back이 pop_front()한 번호보다 크면 Stack에 push_back()한다.
 * 3-2. Stack의 back이 pop_front()한 번호보다 작으면 Recipients를 확인한다.
 * 3-3. Recipients가 비어있거나, Recipients의 back이 Stack의 back보다 작으면 Stack의 back을 Recipients에 push_back()한다.
 * 3-4. Recipients의 back이 Stack의 back보다 크면 "Sad"를 return한다.
 * 3-5. Recipients의 back이 Stack의 back보다 작으면 Stack에 push_back()한다.
 * 4. Deque이 빌 때까지 2~3을 반복한다.
 * 5. Stack이 빌 때까지 3-3 ~ 3-4를 반복한다.
 * 6. "Nice"를 return한다.
 */

#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

void print(vector<int>& stack, vector<int>& recipients) {
    cout << "----- Stack -----" << "\n";

    for (int s: stack) {
        cout << s << " ";
    }

    cout << "\n";

    cout << "----- Recipients -----" << "\n";

    for (int r: recipients) {
        cout << r << " ";
    }

    cout << "\n" << "----- -----" << "\n";
}

bool popStack(vector<int>& stack, vector<int>& recipients, bool clearAll, int target) {
    while (!stack.empty()) {
        int currentStack = stack.back();

        // 3-3
        if (recipients.empty() || recipients.back() < currentStack) {
            if (!clearAll && target < currentStack) {
                // cout << "ADD TO S " << target << "\n";
                stack.emplace_back(target);
                // print(stack, recipients);
                return true;
            }

            // cout << "ADD TO R " << currentStack << "\n";
            recipients.emplace_back(currentStack);
            // print(stack, recipients);
            stack.pop_back();
        } else {
            // 3-4
            // return "Sad";
            return false;
        }
    }

    if (!clearAll) {
        // cout << "ADD TO S " << target << "\n";
        stack.emplace_back(target);
        // print(stack, recipients);
    }

    return true;
}

string getResult(deque<int>& people) {
    vector<int> stack;
    vector<int> recipients;

    while (!people.empty()) {
        // 2
        int current = people.front();
        people.pop_front();

        // 3-1
        if (stack.empty() || stack.back() > current) {
            // cout << "ADD TO S " << current << "\n";
            stack.emplace_back(current);
            // print(stack, recipients);
        } else {
            // 3-2
            bool popResult = popStack(stack, recipients, false, current);

            if (!popResult) {
                return "Sad";
            }
        }
    }

    // 3-5
    bool popResult = popStack(stack, recipients, true, 0);

    // 3-6
    return popResult ? "Nice" : "Sad";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> people(n);

    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    cout << getResult(people) << "\n";

    return 0;
}
