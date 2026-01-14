#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string str;

    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> str;

        bool isGroupWord = true;
        char visited[26] = { false };

        for (int i = 0; i < str.length(); i++) {
            if (i > 0 && str[i] != str[i-1]) {
                if (visited[str[i] - 'a'] == false) {
                    visited[str[i] - 'a'] = true;
                } else {
                    isGroupWord = false;
                    break;
                }
            } else if (i == 0) {
                visited[str[i] - 'a'] = true;
            }
        }

        if (isGroupWord) {
            count++;
        }
    }

    cout << count;

    return 0;
}
