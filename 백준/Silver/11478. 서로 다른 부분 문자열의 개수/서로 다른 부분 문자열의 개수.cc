#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string word;
    cin >> word;

    unordered_set<string> separatedWords;
    int index = 1;

    while (true) {
        if (index >= word.length()) {
            // 전체 문자열 포함
            cout << separatedWords.size() + 1 << "\n";
            break;
        }

        for (int i = 0; i < word.length(); i++) {
            if (i + index <= word.length()) {
                separatedWords.emplace(word.substr(i, index));
            }
        }

        index++;
    }

    return 0;
}
