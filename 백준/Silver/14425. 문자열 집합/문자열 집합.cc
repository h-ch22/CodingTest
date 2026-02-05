#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_set<string> sentences;

    for (int i = 0; i < n; i++) {
        string sentence;
        cin >> sentence;

        sentences.insert(sentence);
    }

    int count = 0;

    for (int i = 0; i < m; i++) {
        string sentence;
        cin >> sentence;

        if (sentences.find(sentence) != sentences.end()) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
