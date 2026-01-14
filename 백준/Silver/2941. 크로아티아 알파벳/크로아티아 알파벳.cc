#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string word;
    cin >> word;

    int count = 0;

    string alphabets[] = {
        "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
    };

    for (const string& a: alphabets) {
        regex pattern(a);
        word = regex_replace(word, pattern, "+");
    }

    for (char c: word) {
        if (c == '+') {
            count++;
        } else {
            if (0 <= c - 'a' && c - 'a' < 26) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
