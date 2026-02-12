#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int fruitCounts[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> fruits(n);

    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    int maxLength = 0;
    int left = 0;
    int right = 0;
    int distinctTypes = 0;

    for (right = 0; right < n; right++) {
        if (fruitCounts[fruits[right]] == 0) {
            distinctTypes++;
        }

        fruitCounts[fruits[right]]++;

        while (distinctTypes > 2) {
            fruitCounts[fruits[left]]--;

            if (fruitCounts[fruits[left]] == 0) {
                distinctTypes--;
            }

            left++;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << "\n";

    return 0;
}
