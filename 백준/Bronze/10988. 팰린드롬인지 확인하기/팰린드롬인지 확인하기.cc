#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string word;
    cin >> word;

    string reversedWord;

    reverse_copy(word.begin(), word.end(), back_inserter(reversedWord));

    cout << (reversedWord == word) ? 1 : 0;

    return 0;
}
