#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> counts(26);

    string str;
    cin >> str;

    for (char c: str) {
        counts[tolower(c) - 'a']++;
    }

    auto maxElem = max_element(counts.begin(), counts.end());
    int maxIdx = distance(counts.begin(), maxElem + 1);

    if (count(counts.begin(), counts.end(), counts[maxIdx - 1]) > 1) {
        cout << "?";
    } else {
        cout << static_cast<char>(maxIdx - 1 + 'A');
    }

    return 0;
}
