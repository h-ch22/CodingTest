#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s;

    cin >> n >> m >> s;

    int patternCount = 0;
    int answer = 0;

    for (int i = 0; i < m - 2; i++) {
        if (s[i] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
            patternCount++;

            if (patternCount == n) {
                answer++;
                patternCount--;
            }

            i++;
        } else {
            patternCount = 0;
        }
    }

    cout << answer << "\n";

    return 0;
}
