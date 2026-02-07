#include <iostream>
#include <string>

using namespace std;

pair<int, int> recursion(const string& s, int l, int r, int cnt) {
    if (l >= r) return make_pair(1, cnt + 1);
    if (s[l] != s[r]) return make_pair(0, cnt + 1);

    return recursion(s, l+1, r-1, cnt + 1);
}

pair<int, int> isPalindrome(const string& s) {
    return recursion(s, 0, s.length() - 1, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string sentence;
        cin >> sentence;

        pair<int, int> p = isPalindrome(sentence);

        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
