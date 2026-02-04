#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<string> words;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }

    vector<string> v(n);

    copy(words.begin(), words.end(), v.begin());
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++) {
        if (v[i] != "") {
            cout << v[i] << "\n";
        }
    }

    return 0;
}
